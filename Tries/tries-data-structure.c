#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Program to implement Tries

typedef struct _tries {
	char university[40];
	struct _tries* leaves[10];
} trieNode;

trieNode* ROOT = NULL;

trieNode* createNode() {
	trieNode* tempNode =  (trieNode*) malloc(sizeof(struct _tries));
	if(tempNode != NULL) {
		int i=0;
		for(i=0;i<10;i++) {
			tempNode->leaves[i] = NULL;
		}		
		return tempNode;
	} else {
		return NULL;
	}
}

int* makeDigits(int year, int* digits) {	
	int rm10, dvsr, quot;	
    rm10 = year / 10;
    dvsr = 1;
    while(dvsr <= rm10) {	
        dvsr *= 10;
    }
	int count = 0;
    while(dvsr) {
        quot = year / dvsr;
        digits[count++] = quot;
        year %= dvsr;
        dvsr /= 10;
    }
    return digits;
}

void insertion(int yearFound, char* universityName) {
	int i = 0;	
	
	int tempYear = yearFound;
    int count = 0, tens = 10;
    while(tempYear) {
    	tempYear = tempYear / tens;
    	count++;
	}
	int numbers[count];
	int* digits = makeDigits(yearFound, numbers);
	trieNode* trav = ROOT;
	
	for(i=0;i<count;i++) {
		if(trav->leaves[digits[i]] == NULL) {
			trieNode* tempNext = createNode();
			trav->leaves[digits[i]] = tempNext;
			trav = tempNext;
			if(count-1 == i) {					
				strncpy(trav->university, universityName, 39);
				break;
			}
			continue;
		} else if(trav->leaves[digits[i]] != NULL){
			trav = trav->leaves[digits[i]];
		}
	}
	printf("\n\nInserted in the Data Structure\n\n");
}

int searching(int yearFound, char* universityName) {	
	int tempYear = yearFound;
    int count = 0, tens = 10;
    while(tempYear) {
    	tempYear = tempYear / tens;
    	count++;
	}
	int numbers[count];
	int* digits = makeDigits(yearFound, numbers);
	trieNode* trav = ROOT;	
	int i=0;
	for(i=0;i<count;i++) {
		if(trav->leaves[digits[i]] != NULL) {			
			trav = trav->leaves[digits[i]];
			if(count-1 == i && !strcmpi(trav->university, universityName)) {				
				return 0;
			}
			continue;
		}
	}
	return 1;
}

int deletion(int yearFound, char* universityName) {
	if(searching(yearFound, universityName)) {
		return 1;	
	}
	int tempYear = yearFound;
    int count = 1, tens = 10;
    while(tempYear) {
    	tempYear = tempYear / tens;
    	count++; tens *= 10;
	}
	int numbers[count];
	int* digits = makeDigits(yearFound, numbers);
	trieNode* deletionAddress[count];
	trieNode* trav = ROOT;	
	int i = 0, itr = 0;
	for(i=0;i<count;i++) {
		deletionAddress[itr++] = trav->leaves[digits[i]];
		trav = trav->leaves[digits[i]];		
	}
	int j=0, k=0;
	for(i=count-1;i>=0;i--) {
		int temp = 0;
		for(j=0;j<10;j++) {
			if(deletionAddress[i]->leaves[j] != NULL) {
				temp = 1;
				break;
			}
		}
		if(temp == 0) {
			if(i-1 >= 0) {
				for(k=0;k<10;k++) {
					if(deletionAddress[i-1]->leaves[k] == deletionAddress[i]) {
						deletionAddress[i-1]->leaves[k] = NULL;
						break;
					}
				}

			}
			free(deletionAddress[i]);
		} else {
			if(!stricmp(deletionAddress[i]->university, universityName)) {
				memset(deletionAddress[i], '\0', 40);
			}			
		}
	}
	return 0;
}

int main() {
	printf("\nTrie Data Structure.\n\n");
	int choice = 5;
	int yearFound = 0;
	char universityName[40];
	ROOT = createNode();
	while(1) {
		printf("1. Insertion\n2. Searching\n3. Deletion\n4. Exit \n>>> ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the year >>> ");
				scanf("%d", &yearFound);
				printf("Enter the Name of the University >>> ");
				scanf("%39s", universityName);
				insertion(yearFound, universityName);
				break;
			case 2:
				printf("Enter the year >>> ");
				scanf("%d", &yearFound);
				printf("Enter the Name of the University >>> ");
				scanf("%39s", universityName);
				if(!searching(yearFound, universityName)) {
					printf("\n\n%s University Found in the Data Structure\n\n", universityName);
				} else {
					printf("\n\nUniversity Not Found!\n\n");
				}
				break;
			case 3:
				printf("Enter the year >>> ");
				scanf("%d", &yearFound);
				printf("Enter the Name of the University >>> ");
				scanf("%39s", universityName);
				if(!deletion(yearFound, universityName)) {
					printf("\n\n%s University Detail deleted\n\n", universityName);
				} else {
					printf("\n\nUniversity Not Found!\n\n");
				}
				break;
			case 4:
				printf("\n\nFreeing the memory\n");
				exit(0);
				break;
			default:
				printf("\n\nWrong Choice\n\n");
		}
	}
}
