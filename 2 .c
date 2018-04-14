// Функция копирует все элементы списка source в пустой список destination 
void copy_list(list_t* source, list_t* destination) 
{ 
// второй список должен быть пустым 
if (destination->size != NULL) 
{ 
printf("Destination list need to be empty!\n"); 
return; 
} 

node_t* curr_src = source->head; // source 
node_t* curr_dest = destination->head; // destination 

// пробегаемся по первому списку 
while (curr_src != NULL) 
{ 
// создаем новый элемент, такой же как и текущий элемент первого списка 
node_t* p_new_node = create_node(curr_src->data, NULL); 

// если второй список не пустой 
if (curr_dest != NULL) 
{ 
// перемещаемся к последнему элементу второго списка 
while (curr_dest->next != NULL) 
{ 
curr_dest = curr_dest->next; 
} 

// включаем новый элемент во второй список 
curr_dest->next = p_new_node; 
} 
// если пустой 
else 
{ 
// кладем новый элемент во второй список и делаем его первым 
destination->head = p_new_node; 
curr_dest = destination->head; 
} 

curr_src = curr_src->next; 
destination->size++; // увеличиваем счетчик элементов второго списка 
} 
} 

int main() 
{ 
/* 
Создаем новый связный список. 
Храним на стеке указатель на список. 
*/ 
list_t* plist = create_list(); 
list_t* pdest = create_list(); 

// Добавляем в конец списка i-ое значение 
for (int i = 0; i<10; ++i) 
{ 
append_list(plist, i); 
} 

/* Копируем список plist в пустой список pdest*/ 
copy_list(plist, pdest); 
}}