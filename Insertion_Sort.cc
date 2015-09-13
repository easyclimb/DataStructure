class Solution {
public:
    void insertionSort(int arr[], int n) {
        int key ,
        for(int i = 1; i < n; i++) {
            key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] >= key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    //Time : O( n^2)
    //Space : O(1)
    //Boundary Cases : insertion sort takes maximum time to sort if elements are sorted in reverse order
    //And it takes minimum time (O(n)) when elements are already sorted
    //Stable: yes
    //Uses: Insertion sort is used when number of elements is small. It can also be used when input array is almost sorted
    //only few elements are misplaced in complete big array
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN), *cur = &dummy;
        dummy.next = head;
        while(cur->next) {
            if(cur->val <= cur->next->val)
                cur = cur->next;
            else insert(&dummy, cur, cur->next);
        }
        return dummy.next;
    }
    
    void insert(ListNode* head, ListNode* tail, ListNode* node) { 
        ListNode *cur = head;
        while(node->val > cur->next->val)
            cur = cur->next;
        tail->next = node->next;  //node插入cur和cur->next之间，cur指向的是需要插入的位置的前置位置
        node->next = cur->next;
        cur->next = node;
    }
};
