struct node* CopyList(struct node* head) 
{
   struct node* current = head;      
   if (head == NULL) return NULL;
   else 
    {
      struct node* newList = malloc(sizeof(struct node));   
      newList->data = current->data;
      newList->next = CopyList(current->next);  
      return(newList);
   }
}