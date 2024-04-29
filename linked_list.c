#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 
    struct student{
     
        char ad[15];
        char soyad[15];
        int numara;
        int i;
        struct student *next;
     
    };
    
    struct student *head= NULL;
        struct student *l= NULL;

    struct student *tail= NULL;
    
    
    
    
    
    
    int addstudent(char ad[], char soyad[], int numara){
        
        if(head==NULL){
            
            struct student *new = (struct student *)malloc(sizeof(struct student));
            strcpy(new->ad, ad);
            strcpy(new->soyad, soyad);
            new->numara=numara;
            
            new->next=NULL;
            head=tail=new;
        }
        
        else{
            
            struct student *new = (struct student *)malloc(sizeof(struct student));
            strcpy(new->ad, ad);
            strcpy(new->soyad, soyad);
            new->numara=numara;
            new->next=NULL;
            
            tail->next=new;
            tail=new;
        }
        
        
    }
    
    int delete(int numara){
        
        struct student *prev = NULL;
        struct student *index = head;
        
        if(head==NULL){
            
            printf("liste bos \n\n");
            return 1;
        }
        
        if(head->numara==numara){
            
            struct student *t = head;
            head= head->next;
            free(t);
            return 1;
        }
        
        while(index!=NULL && index->numara!=numara){
            
            prev=index;
            index=index->next;
        }
        
        if(index==NULL){
            
            printf("arama bulunmadi \n\n");
            return 1;
        }
        
        prev->next =index->next;
        
        if(tail->numara==numara){
            
            tail=prev;
        
        }
        
        free(index);
        
        return 1;
    }
    
    
    
    struct student *find_node(struct student *head, int studentId) {
	struct student *temporary = head;
	while (temporary != NULL) {
		if(temporary->numara == studentId) return temporary;
		temporary = temporary->next;
	}
	return NULL;
}
    
    void print(){
        
        struct student *index = head;
        
        while(index!=NULL){
            
            printf("ad: %s\tsoyad: %s\tnumara: %d\n\n", index->ad, index->soyad, index->numara);
            index=index->next;
        }
    }
    
    

    int main()
    {
     
     
    struct student *ptr;
    int n;
    int i;
    int k=1;
    int numara;
    
   
    
    addstudent("serbil", "ustebay",123456);
    addstudent("ayse", "gul",123457);
   
    
    
    while(k!=0){
    
    printf("ne yapmak istiyorsun \n\n ogrenci ekleme icin (1)\n liste goster icin (2)\n ogrenci silmek icin (3)\n ogrenci aramak icin (4)\n");
    scanf("%d", &k);
    
    switch(k){
        
        case 1:
        
           
        printf("kac ogrenci eklemek istiyorsun\n");
        scanf("%d", &n);
           
        ptr = (struct student*) malloc(n * sizeof(struct student));
            
        for(i = 0; i < n; ++i)
        {
            printf("ad, soyad, numara: \n");
            scanf("%s %s %d", (ptr+i)->ad, (ptr+i)->soyad, &(ptr+i)->numara);
            addstudent((ptr+i)->ad, (ptr+i)->soyad, (ptr+i)->numara);
        }
        
        break;

        case 2:
        
        print();

        break;
        
        case 3:
        
        printf("silmek istedigin ogrenci numarasi gir\n");
        scanf("%d", &numara);
        delete(numara);
        
        break;
        
        case 4:
        
        printf("aradigin ogrenci numarasi gir \n");
        scanf("%d", &numara);
        
        l = find_node(head, numara);
				if(l == NULL) {
					printf("ogrenci bulunmadi\n\n");
				} else {
					 printf("ad: %s\tsoyad: %s\tnumara: %d\n\n", l->ad, l->soyad, l->numara);
				}
        
        break;
        
    }
    }
   return 0;
}