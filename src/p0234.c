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


const struct ListNode * get_second_half_pointer(const struct ListNode *head)
{
    /*
     * Returns a pointer to the first element in the 2nd half of a linked list.
     * If the linked list has odd number of nodes, pointer to element after mid
     * element is returned.
     */
    const struct ListNode *fast = head;
    if (head == NULL || head->next == NULL)
        return NULL;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        head = head->next;
    }
    /* If odd number of nodes, skip the mid node */
    if (fast != NULL)
        head = head->next;
    return head;
}


bool linked_list_starts_with(
    const struct ListNode *main_list,
    const struct ListNode *partial_list
)
{
    /*
     * Returns true if `main_list` starts with `partial_list`.
     */
    bool result = true;
    while (
        partial_list != NULL
        && main_list != NULL
        && partial_list->val == main_list->val
    ) {
        main_list = main_list->next;
        partial_list = partial_list->next;
    }
    if (partial_list != NULL)
        result = false;
    return result;
}


void free_linked_list(struct ListNode *head)
{
    /*
     * Frees up dynamic memory allocated to linked list.
     */
    struct ListNode *temp;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}


struct ListNode * create_reversed_linked_list(const struct ListNode *head)
{
    /*
     * Creates a new reversed linked list (without changing the original list)
     */
    struct ListNode *temp, *reversed_list = NULL;
    while (head != NULL) {
        temp = (struct ListNode *) malloc(sizeof(struct ListNode));
        temp->val = head->val;
        temp->next = reversed_list;
        reversed_list = temp;
        head = head->next;
    }
    return reversed_list;
}


bool is_palindrom(struct ListNode *head)
{
    /*
     * Checks if the linkeds list is a palindrome.
     */
    const struct ListNode *second_half;
    struct ListNode *second_half_reversed;
    bool result;
    if (head == NULL)
        return false;
    if (head->next == NULL)
        return true;
    second_half = get_second_half_pointer(head);
    /* Create a reversed linked list for the 2nd half */
    second_half_reversed = create_reversed_linked_list(second_half);
    result = linked_list_starts_with(head, second_half_reversed);
    free_linked_list(second_half_reversed);
    return result;
}
