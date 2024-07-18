#include<stdio.h>  
#include<stdlib.h>
#include<string.h>


#define WORDS 100
#define WORD_LEN 100

typedef struct{
    char word[WORD_LEN];
    char meaning[WORD_LEN]
}Word;

Word vocabulary[WORDS];
int numWords=0;
void addword();
void quiz();
void displayprogress(); 

int main()
{
    int choice;
    while(1)
    {
        printf("\nLanguage learning app\n");

        printf("1.Add a new word to vocabulary\n");
        printf("2.Quiz");
        printf("3.Display Progress\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
               addword();
               break;
            case 2:
               quiz();
               break;
            case 3: 
               displayprogress();
               break;
            case 4:
               printf("Exiting the program\n");
               exit(0);
            default:
               printf("Invalid choice\n");
        }
    }
    return 0;
}
void addword()
{
   if(numWords==WORDS)
   {
      printf("Cannot add new words\n");
      return;
   }
   printf("Enter the word:");
   scanf("%s", vocabulary[numWords].word);
   printf("Enter the meaning:");
   scanf("%s",vocabulary[numWords].meaning);
   numWords++;
   printf("Word added successfully\n");
}
void quiz()
{
   if(numWords==0)
   {
     printf("No word in the vocabulary\n");
     return ;
   }
   int score=0;
   printf("Starting practice quiz\n");
   for(int i=0;i<numWords;++i)
   {
      printf("What is the meaning of '%s'?\n",vocabulary[i].word);
      char ans[WORD_LEN];
      printf("Your answer:");
      scanf("%s",ans);
      if(strcmp(ans, vocabulary[i].meaning)==0)
      {
         printf("Correct\n");
         score++;
      }
      else
      {
         printf("Incorrect.The correct answer is %s\n",vocabulary[i].meaning);
      }

   }
   printf("Quiz completed\n");
   printf("Your score:%d/%d\n",score,numWords);
}
void displayprogress()
{
   printf("Display progress\n");
   printf("You have learned %d words\n",numWords);
}