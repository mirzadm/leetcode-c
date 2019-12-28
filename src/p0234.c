/*
 * Given a singly linked list, determine if it is a palindrome.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


bool is_palindrom(struct ListNode* head)
{
    struct ListNode *slow, *fast, *second_half = NULL, *temp;
    bool palindrome = true;
    /* Cover edge cases */
    if (head == NULL)
        return false;
    if (head->next == NULL)
        return true;
    /* Find middle node */
    slow = head;
    fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast != NULL)
        slow = slow->next;
    /* Create a reversed linked list for the 2nd half */
    while (slow != NULL) {
        temp = (struct ListNode *) malloc(sizeof(struct ListNode));
        temp->val = slow->val;
        temp->next = second_half;
        second_half = temp;
        slow = slow->next;
    }
    /* Compare 1st half and reversed 2nd half */
    temp = second_half;
    while (second_half != NULL) {
        if (head->val != second_half->val) {
            palindrome = false;
            break;
        }
        second_half = second_half->next;
        head = head->next;
    }
    /* Free allocated memory */
    second_half = temp;
    while (second_half != NULL) {
        temp = second_half->next;
        free(second_half);
        second_half = temp;
    }
    return palindrome;
}


int main()
{
    struct ListNode a, b, c;
    a.val = 1;
    b.val = 2;
    c.val = 1;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    if (is_palindrom(&a))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
