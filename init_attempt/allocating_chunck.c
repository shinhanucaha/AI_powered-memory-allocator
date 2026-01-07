//function to allocate memory chunck my own (custom)
//since it will be a pointer that i have to return well i will use sbrk() system call well um i need to check how will i do that 
#include<stdio.h>
#include<stddef.h>
#include<unistd.h> // later got it it will need if you use sbrk() in your code
void* alloc_memory(long long n , size_t req_size){
    void* alloted =  sbrk(size + META_SIZE) ;
    if(alloted == (void*)-1){ // fixed if we use sbrk(size) in if condition it will be called twice 
        
     return NULL ;  
    }
    while(temp != NULL){
        if(temp.size >= req_size){
            temp.is_free = false ;
            break ;
        }
    if(temp-next == NULL){
    temp.next = alloted ;
    temp.is_free = false ;
    temp.size = req_size ; }

    temp = temp->next ;
    }

    (char*)meta_alloted = (char*)alloted ; //used to move the pointer to the size of metadata to return the usable block memory pointer
    meta_alloted = meta_alloted + size_of(metadata) ;
    alloted = void * meta_alloted ;
    return alloted ; // change all alloted to temp ...
}

// main function to run it 
int main(){
    int size = 10 ;
    void* alloted ;
    void* before ;
    before = sbrk(0);
    alloted = alloc_memory(0,size) ;
    void* after = sbrk(0) ;
    printf("%p,%p,%p",before,alloted,after) ;//output:0x5d30ec510000,0x5d30ec510000,0x5d30ec51000a
    //it's cool let me see the size 
    printf("%ld",(char*)after-(char*)before) ; //casting to char pointer will help count every bytes as division becomes 1 now 
    return 0 ;
}