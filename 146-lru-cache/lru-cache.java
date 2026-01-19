import java.util.*;

class LRUCache {

    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    Node head = new Node(-1,-1);
    Node tail = new Node(-1,-1);
    int cap;
    HashMap<Integer, Node> mp = new HashMap<>();

    public LRUCache(int capacity) {
        cap= capacity;
        head.next = tail;
        tail.next = head;
    }
    
    public int get(int key) {
        if(mp.containsKey(key)) {
            Node found = mp.get(key);
            mp.remove(key);
            deleteNode(found);
            addNode(found);
            mp.put(key, head.next);
            return found.value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(mp.containsKey(key)){
            Node curr = mp.get(key);
            mp.remove(key);
            deleteNode(curr);
        }
        if(mp.size()==cap) {
            mp.remove(tail.prev.key);
            deleteNode(tail.prev);
        }
        addNode(new Node(key, value));
        mp.put(key, head.next);
    }

    private void addNode(Node node) {
        Node curr = head.next;
        node.next = curr;
        curr.prev = node;
        node.prev = head;
        head.next = node;
    }
    private void deleteNode(Node node) {
        Node next = node.next;
        Node prev = node.prev;

        next.prev = prev;
        prev.next = next;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */