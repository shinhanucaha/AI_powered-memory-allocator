//what i want here as per i know there will be a metadata before the address pointed by free_me making is_free(variable) as 1 that will
//indicate that the memory is free;
#define META_SIZE
#define HEAD_OF_LIST
struct metadata{
    bool is_free ; //can not be initialised here that is only done in c++
    void* pointr ;
    void* next ;
}
void  free_it(void* free_me){
void * temp = HEAD_OF_LIST ;
while(temp != NULL){
 if(temp->next == free_me){
    
 }
}
}
//create a linked list that will keep track of freed block 
//i need a next pointer to travesel and a head pointer to keep linked list known 
//this linked list will be of metadata addresses so i need a next in that datatype 
//head pointer need as a global pointer 