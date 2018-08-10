/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2  ); // capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/


/*
    NOTE:
    1. In LRU, get and put operation will both affect the order of elements! (not just put operation)
    2. Sacrifice space to gain time. 
    3. Don't use [deque] !! Since my implementation stores each iterator (actually a pointer) of the queue (or list), I need to access that element using these iterators. However since deque would expand its memory, with its unknown implementation details (like a Black Box to us), these iterators may don't work --- when key_deque.erase(cache[key].second) will generate 'Runtime Error', although *(cache[key].second) could get the correct element value in key_deque.
    Just use STL [list].
    4. Data structure I used in this problem is complex and deserve good attention.
*/

class LRUCache {
public:
    LRUCache(int capacity) {
        cache_capacity = capacity;
        count = 0;
    }
    int get(int key) {
        if (cache.count(key) > 0) {  // There exists this key in cache
            int val = cache[key].first;
            /*
            // If STL [deque] is used, key_deque.erase(cache[key].second); will encounter 'Runtime Error'.
            // Bellow method is still work, but meaningless (since time complexity is to big).
            for (deque<int>::iterator it = key_deque.begin(); it != key_deque.end(); it++)
                if (*it == key) {
                    key_deque.erase(it);
                    break;
                }
            */
            key_deque.erase(cache[key].second);
            key_deque.push_front(key);
            cache[key].second = key_deque.begin();
            return val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.count(key) > 0) {  // There exists this key in cache
            // Update the key's position in deque to the head/front
            key_deque.erase(cache[key].second);
            key_deque.push_front(key);
            // Update its value in cache.
            cache[key] = {value, key_deque.begin()};
        } else {
            if (key_deque.size() >= cache_capacity) {  // Remove old (key,value)
                int old_key = key_deque.back();
                key_deque.pop_back();
                cache.erase(old_key);
            }
            // Add new (key,value)
            key_deque.push_front(key);
            cache[key] = {value, key_deque.begin()};
        }
    }
private:
    typedef list<int>::iterator DEQUE_ITER;
    unordered_map<int, pair<int, DEQUE_ITER> > cache;  // key is the input key, value is pair<value, iterator of key in key_deque>
    list<int> key_deque;  // control the in & out order. stores the keys.
    int cache_capacity;
    int count;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */