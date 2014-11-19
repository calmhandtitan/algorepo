#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
	int prefix_count;
	bool isEnd;
	struct node *child[26];
}*head;

void init()
{
//	head = (node*)malloc(sizeof(node));
	head = new node();
	head->isEnd = false;
	head->prefix_count = 0;
}

void insert(string word)
{
	node *current = head;
	current->prefix_count++;
	
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';	//extrct first character of word
		if(current->child[letter] == NULL)
			current->child[letter] = new node();

		current->child[letter]->prefix_count++;
		current = current->child[letter];		
	}
	current->isEnd = true;
}

bool search(string word)
{
	node *current = head;
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';
		if(current->child[letter] == NULL)
			return false;		//not found
		current = current->child[letter];
	}
	return current->isEnd;
}

int words_with_prefix(string prefix)
{
	node *current = head;
	for(int i = 0; i < prefix.length() ; ++i)
	{
		int letter = (int)prefix[i] - (int)'a';
		if(current->child[letter] == NULL)
			return 0;
		else
			current = current->child[letter];
	}
	return current->prefix_count;
}


int main()
{
	init();
	string s = "chandan";
	insert(s);
	s = "mittal";
	insert(s);
	s = "chirag";
	insert(s);
	s = "shashank";
	insert(s);
	s = "abhinav";
	insert(s);
	s = "arun";
	insert(s);
	s = "abhishek";
	insert(s);
	

	if(search("chandan"))
		printf("found chandan\n");
	if(search("arun"))
		printf("found arun\n");
	if(search("abhi"))
		printf("found abhi\n");
	else
		printf("not found abhi\n");
	
	printf("no of words with prefix abhi are %d\n",words_with_prefix("abhi"));
	printf("no of words with prefix ch are %d\n",words_with_prefix("ch"));
	printf("no of words with prefix k are %d\n ",words_with_prefix("k"));
	
	

	return 0;
}
