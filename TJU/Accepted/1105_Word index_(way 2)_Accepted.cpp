#include <iostream.h>
#include <string.h>

char word [83681][6];
int wordNumber = 0;

char testWord[6];

char pos[5] = { ' ', ' ', ' ', ' ', ' '};

char terminator = 'z';

main()
{


 int i;
 int length;
 int found;

 for(length=1;length<=5;length++)
 {

   for(pos[0]='a'; pos[0]<=terminator; pos[0]++ )
   {
    if ( length == 1 )
    {
     word[wordNumber][0] = pos[0];
     word[wordNumber][1] = '\0';
     wordNumber++;
     continue;
    }
    for(pos[1]=pos[0]+1; pos[1]<=terminator; pos[1]++ )
    {
     if ( length == 2 )
     {
      word[wordNumber][0] = pos[0];
      word[wordNumber][1] = pos[1];
      word[wordNumber][2] = '\0';
      wordNumber++;
      continue;
     }
     for(pos[2]=pos[1]+1; pos[2]<=terminator; pos[2]++ )
     {
      if ( length == 3 )
      {
       word[wordNumber][0] = pos[0];
       word[wordNumber][1] = pos[1];
       word[wordNumber][2] = pos[2];
       word[wordNumber][3] = '\0';
       wordNumber++;
       continue;
      }
      for(pos[3]=pos[2]+1; pos[3]<=terminator; pos[3]++ )
      {
       if ( length == 4 )
       {
	word[wordNumber][0] = pos[0];
	word[wordNumber][1] = pos[1];
	word[wordNumber][2] = pos[2];
	word[wordNumber][3] = pos[3];
	word[wordNumber][4] = '\0';
	wordNumber++;
	continue;
       }
       for(pos[4]=pos[3]+1; pos[4]<=terminator; pos[4]++ )
       {
	word[wordNumber][0] = pos[0];
	word[wordNumber][1] = pos[1];
	word[wordNumber][2] = pos[2];
	word[wordNumber][3] = pos[3];
	word[wordNumber][4] = pos[4];
	word[wordNumber][5] = '\0';
	wordNumber++;
       }
      }
     }
    }
   }
  }

 while ( 1 )
 {
  found = 0;
  cin >> testWord;
  if ( cin.eof() ) break;
  for(i=0;i<83681;i++)
  {
   if(strcmp(word[i], testWord) == 0)
   {
    found = 1;
    break;
   }
  }
  if ( found ) cout << i+1 << endl;
  else cout << 0 << endl;
 }
}


