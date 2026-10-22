/**
 * // Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {

    if (head == NULL)
        return NULL;

    struct Node *curr = head;

    // Step 1: Create a copy after every original node
    while (curr != NULL) {
        struct Node *copy = malloc(sizeof(struct Node));

        copy->val = curr->val;
        copy->next = curr->next;
        copy->random = NULL;

        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Set random pointers of copied nodes
    curr = head;

    while (curr != NULL) {
        struct Node *copy = curr->next;

        if (curr->random != NULL)
            copy->random = curr->random->next;

        curr = copy->next;
    }

    // Step 3: Separate original and copied lists
    curr = head;
    struct Node *copyHead = head->next;

    while (curr != NULL) {
        struct Node *copy = curr->next;

        curr->next = copy->next;

        if (copy->next != NULL)
            copy->next = copy->next->next;

        curr = curr->next;
    }

    return copyHead;
}
