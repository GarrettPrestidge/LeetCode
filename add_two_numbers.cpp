// Here, we are trying to take two reversed linked lists, add their digits together, 
// and produce a linked list that is a sum of their values

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode* l3 = new ListNode(0); // initialize the result LL with a 0
        ListNode* guide = l3;

        // continue until each list has reached it's end and all carries have
        // been accounted for.
        // this method will individually add each digit, instead of all at once.
        // this method will run faster, use less memory, and will not result
        // in memory overflow from very large digits.
        while( l1 != nullptr || l2 != nullptr || carry )
        {
            int sum = 0;

            if (l1 != nullptr)  //check for if we've reached the end of the LL
            {
                sum += l1->val; //add the current value of l1 to our sum
                l1 = l1->next;  //travers to the next value in the l1 LL
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;   //add the previous carry
            carry = sum/10; //check for a carry
            sum %= 10;      //get the first digit of sum

            ListNode* newNode = new ListNode( sum );  //creates a new node that is the current digit in the result
            guide->next = newNode;      //the guide makes its next value the new node we've just created
            guide = guide->next;        //the guide points to the next value
        }

        l3 = l3->next;
        return l3;  //test output
    }
};
