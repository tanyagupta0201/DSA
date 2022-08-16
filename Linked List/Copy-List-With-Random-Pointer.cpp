// https://leetcode.com/problems/copy-list-with-random-pointer/

// SOLUTION 1: USING MAP
// TC = O(N) + O(N)
// SC = O(N)
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> m; // Link old node to the new node

        int i = 0;

        // 1) create new nodes, fill values and link in map
        Node *ptr = head;

        while (ptr)
        {
            m[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }

        // 2. go through old head agin, use link[oldNode], which is newNode
	    	// Key point : link[any_node_here] points the corresponding new_copied_node
        ptr = head;
        while (ptr)
        {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }

        return m[head];
    }
};


// SOLUTION 2: THREE PASS SOLUTION
// TC = O(N) + O(N) + O(N)
// SC = O(1)

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node *iter = head; 
        Node *front = head;

        // First round: make copy of each node,
        // and link them together side-by-side in a single list, each after the original node
        while (iter != NULL) 
        {
            front = iter->next;

            Node *copy = new Node(iter->val); // deep copy node
            iter->next = copy;
            copy->next = front;

            iter = front;
        }

        // Second round: assign random pointers for the copy nodes.
        iter = head;
        while (iter != NULL)
        {
            if(iter->random != NULL) 
            {
                iter->next->random = iter->random->next;
            }
            
            // we move 2 steps because we don't want to go to deep nodes
            iter = iter->next->next;
        }

        // Third round: restore the original list, and extract the copy list.
        iter = head;
        Node *pseudoHead = new Node(0);
        Node *copy = pseudoHead;

        while (iter != NULL) 
        {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
        }

        return pseudoHead->next;
    }
};

