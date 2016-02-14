// StringManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
//#define _CRT_SECURE_NO_WARNINGS

char* ReverseEditable(char string[]) {
	int start = 0, end = 0, length = 0, length1 = 0;

	length = end = length1 = sizeof(string);
	//end--;
	while (length > 0) {
		char temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		start++;
		end--;
		length--;
	}
	string[length1] = '\0';
	return string;
}

char* ReversetNotEditable(char sourcestring[]) {

	int start = 0, end = 0, length = 0, length1 = 0, i = 0;

	length = end = length1 = strlen(sourcestring);// = sizeof(sourcestring) / sizeof(sourcestring[0]);

	//for (i = 0; sourcestring[i]; i++);
	//i = strlen(sourcestring);

	char* targetstring = (char *)malloc(length);
	char* ptr = (char *)malloc(length);
	//	strcpy(ptr, sourcestring);

	end--;
	while (end >= 0) {

		targetstring[start] = sourcestring[end];
		end--;
		start++;
	}

	targetstring[length1] = '\0';

	length = end = length1 = strlen(sourcestring);
	start = 0;
	end--;
	while (end > 0) {
		char temp = ptr[start];
		ptr[start] = ptr[end];
		ptr[end] = temp;
		end--;
		start++;
	}

	return targetstring;

}

//This is a Career Monk String
//String Monk Career a is This
void ReverseWordsInString(char* sourcestring) {

	char* targetString = (char *)malloc(sizeof(sourcestring));

	int ssl = strlen(sourcestring), i = 0;
	targetString[ssl] = '\0';
	int totallength = ssl;
	char word[10];
	while (ssl > 0) {

		int wordlength = 0;
		while (sourcestring[ssl] != ' ')
		{
			wordlength++;
			ssl--;
		}
		wordlength--;
		char *tempword = (char *)malloc(wordlength);
		tempword[wordlength] = '\0';
		int j = 0;

		int targetStringlength = strlen(targetString);
		while (wordlength >= 0)
		{
			targetString[wordlength + targetStringlength] = sourcestring[totallength];
			wordlength--;
			totallength--;
		}

		ssl--;
		//targetString += tempword;
	}


}

void ReverseString(char *ptr, int start, int end) {

	char temp;
	while (start < end && end > 0) {
		temp = ptr[end];
		ptr[end] = ptr[start];
		ptr[start] = temp;
		end--;
		start++;
	}
	//printf("%s", ptr);
}

void ReverseRecursion(char input[], int start, int end)
{
	if (start == end)
	{
		printf("%s \n", input);
		return;
	}
	char temp = input[end];
	input[end] = input[start];
	input[start] = temp;

	ReverseRecursion(input, ++start, --end);

}

void reverse(char *str)
{
	if (*str)
	{
		reverse(str + 1);
		printf("%c", *str);
	}
}

void ReverseWordsInStringRecursion(char sourcestring[]) {

	int start = 0, end = 0;
	int ssl = strlen(sourcestring);
	ReverseString(sourcestring, 0, strlen(sourcestring) - 1);
	char *TargetString = (char *)malloc(sizeof(sourcestring));

	/*while (end <ssl)
	{
		while (sourcestring[end] != ' ')
			end++;

		ReverseString(sourcestring, start, end);
		end++;
		start = end;
	}*/

	for (start = end = 0; end < ssl; end++) {
		if (sourcestring[end] != ' ')
		{
			start = end;
			while (sourcestring[end] != ' ' && end < ssl)
				end++;

			end--;
			ReverseString(sourcestring, start, end);
		}
	}

}

char* ReverseStringwithoutTemp(char* str) {
	int start = 0, end = strlen(str) - 1;
	while (start < end) {
		str[start] = str[start] ^ str[end];
		str[end] = str[end] ^ str[start];
		str[start] = str[start] ^ str[end];

	}
	return str;
}


char Hash(char key) {

	char value;
	switch (key) {
	case 'a':
		value = 'x';
		break;
	case 'b':
		value = 'y';
		break;
	default:
		value = 'z';
		break;
	}

	return value;
}

bool IsIsomorphic(char input1[], char input2[])
{

	if (strlen(input1) != strlen(input2))
		return false;

	for (int i = 0; i < strlen(input1) - 1; i++) {
		if (input2[i] != Hash(input1[i]))
			return false;

	}

	return true;

}
//
//char* CheckChar(char c, char* substring) {
//	int length = strlen(substring);
//
//	for (int i = 0; i++; i < length)
//	{
//		if (substring[i]) != c)
//		continue;
//	}


//}

bool SubstringNTimes(char* input) {
	int i = 0;
	int length = strlen(input);
	char tempstring[10] = "\0";
	int count = 0;
	for (int i = 0; i < length; i++) {
		bool charexists = false;
		int tempstringlength = count = strlen(tempstring);
		if (strlen(tempstring) == 0)
			tempstring[i] = input[i];
		else
		{
			for (int j = 0; j < tempstringlength; j++)
			{
				if (tempstring[j] != input[i])
				{
					charexists = false;

				}
				else
				{
					j = 0;
					if (tempstring[j] == input[i])
					{
						i++;
						continue;
					}
					else
						charexists = true;
					break;
				}
			}

			if (charexists == false)
			{
				tempstring[count] = input[i];
				tempstring[++count] = '\0';
			}
			else
			{
				for (int k = 0; k < tempstringlength; k++)
				{

					if (input[i + k] == tempstring[k])
					{
						if (k == tempstringlength - 1)
						{
							k = 0;
							i = i + tempstringlength;

							if (i == strlen(input))
								return true;

						}
						continue;
					}
				}
			}
		}



	}

}

//Permutation
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
		printf("%s\n", a);
	else
	{
		for (i = 41l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i)); //backtrack
		}
	}
}

void Permuttations(int depth, char *permutation, int *used, char* original) {
	int length = strlen(original);

	if (depth == length)
		printf("%s\n", permutation);
	else
	{
		for (int i = 0; i < length; i++) {
			if (!used[i])
			{
				used[i] = 1;
				permutation[depth] = original[i];

				/*for (int i = 0; i < 3; i++)
					printf("%d", used[i]);
					printf("\ni=%d, depth=%d \n", i, depth);*/
				Permuttations(depth + 1, permutation, used, original);
				used[i] = 0;
			}

		}
	}

}

void Combinations(int depth, char *combination, int start, char *original) {
	int length = strlen(original);

	for (int i = start; i < length; i++) {

		combination[depth] = original[i];
		combination[depth + 1] = '\0';
		printf("%s \n", combination);
		if (i < length - 1)
			Combinations(depth + 1, combination, start + 1, original);

	}

}

/* arr[]  ---> Input Array
data[] ---> Temporary array to store current combination
start & end ---> Staring and Ending indexes in arr[]
index  ---> Current index in data[]
r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end,
	int index, int r)
{
	// Current combination is ready to be printed, print it
	if (index == r)
	{
		for (int j = 0; j < r; j++)
			printf("%d ", data[j]);
		printf("\n");
		return;
	}

	// replace index with all possible elements. The condition
	// "end-i+1 >= r-index" makes sure that including one element
	// at index will make a combination with remaining elements
	// at remaining positions
	for (int i = start; i <= end && end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i + 1, end, index + 1, r);
	}
}

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
	// A temporary array to store all combination one by one
	int data[2];

	// Print all combination using temprary array 'data[]'
	combinationUtil(arr, data, 0, n - 1, 0, r);
}

//ABCCBCBA
//ABBCBA

void RecursiveRemoval(char Input[], int Length)
{
	char temparray[8] = "\0";
	int j = 0;
	bool flag = 0;
	//temparray[0] = '\0';
	for (int i = 0; i < Length && i + 1 < Length; i++)
	{
		if (Input[i] != Input[i + 1])
		{
			temparray[j] = Input[i];
			j++;
			temparray[i + 1] = '\0';
		}
		else i++;

	}
	if (temparray[j] != Input[Length - 1])
		temparray[j] = Input[Length - 1];
	temparray[j + 1] = '\0';

	if (strlen(Input) == strlen(temparray))
	{
		printf("%s", temparray);
		return;
	}

	else
		RecursiveRemoval(temparray, strlen(temparray));
}

//TestStrintg
void MaximumOccuringCharacter(char input[], int length)
{
	int Mappingarray[13];


	for (int i = 0; i < length; i++)
	{
		int count = 1;
		for (int j = 1; j < length; j++)
		{
			if (input[i] == input[j])
			{
				Mappingarray[i] = ++count;
			}
		}
	}

	int maxIndex = 0, maxValue = 0;
	for (int j = 0; j < length; j++)
	{
		if (Mappingarray[j] > maxValue)
		{
			maxIndex = j;
			maxValue = Mappingarray[j];
		}
	}

	printf("%c", input[maxIndex]);
}

char getMaxOccuringChar(char* str)
{
	// Create array to keep the count of individual
	// characters and initialize the array as 0
	int count[1000] = { 0 };

	// Construct character count array from the input 
	// string.
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		count[str[i]]++;

	int max = -1;  // Initialize max count
	char result;   // Initialize result

				   // Traversing through the string and maintaining
				   // the count of each character
	for (int i = 0; i < len; i++) {
		if (max < count[str[i]]) {
			max = count[str[i]];
			result = str[i];
		}
	}

	return result;
}

//Vivekanandav -11
//Vivek - 5
void RemoveCharsfromFirstString(char inputstring1[], int input1length, char inputstring2[], int input2length)
{
	int count[10000] = { 0 };
	int input1lengthcopy = input1length;
	while (input2length > 0)
	{
		count[inputstring2[input2length - 1]] = 1;
		input2length--;
	}

	int i = 0, j = 0, count1 = 0;
	while (i < input1length)
	{
		if (count[inputstring1[i]] == 1 && j < strlen(inputstring1))
		{
			inputstring1[j] = inputstring1[j + 1];
			j++;
		}
		else
		{
			i++;
			j = 0;
		}

		//if (j == strlen(inputstring1) - 1)
		//	inputstring1[j+1] = '\0';

	}
	printf("%s", inputstring1);
}

//int myAtoi(char *str)
//{
//	int res = 0; // Initialize result
//
//				 // Iterate through all characters of input string and
//				 // update result
//	for (int i = 0; str[i] != '\0'; ++i)
//		res = res * 10 + str[i] - 48;
//
//	// return result.
//	return res;
//}

//babbcdbb
void RemovalOfbandac(char input123[], int length) {

	int i = -1, j = 0, count = 0;
	bool flag = 0;
	while (j < length)
	{
		if (input123[j] == 'b')
		{
			j++;
		}
		else input123[++i] = input123[j++];
	}
	input123[++i] = '\0';

	printf("%s", input123);
}

void palindromicsubstrings(char input[], int length)
{

}



int main()
{
	//	char* string = "Vivek";
	//	char string1[] = "Vivekananda";
	////	printf("%s", ReverseEditable(string));
	//	//printf("%s", ReversetNotEditable(string));
	//	//ReverseWordsInString("This is "This is a Career Monk String"a Career Monk String");
	//	char sourcestring[] = "This is a Career Monk String";
	//	//ReverseWordsInStringRecursion(sourcestring);
	//	//ReverseStringwithoutTemp(string1);
	//	int a = 55, b = 600;
	//	printf("\n\na = %d, b = %d \n", a, b);
	//	/*a = a^b;
	//	b = b^a;
	//	a = a^b;* */
	//	a= a^ (b = b ^ (a=b^a));
	//	printf("a = %d, b = %d \n", a, b);

	//char input1[] = "aabbaab", input2[] = "xxyyxxy";

	//if (IsIsomorphic(input1, input2))
	//	printf("Strings are isomporphic");

	//char input1[] = "abcaacabc";
	//if(SubstringNTimes(input1) == true)
	//	printf("string can be constructed using substring multiple times");


	//char str[] = "ABC";
	//char original[] = "ABC";
	//int used[3] = { 0,0,0 };
	//int n = strlen(str);
	////permute(str, 0, n - 1);
	//Permuttations(0, str, used, original);
	//printf("\n \n ******************************** \n");
	//char str1[] = "ABC";
	//char original1[] = "ABC";
	//Combinations(0, str1, 0, original1);

	/*int arr[] = { 1, 2, 3, 4, 5 };
	int r = 2;
	int n = sizeof(arr) / sizeof(arr[0]);
	printCombination(arr, n, r);*/

	// RecursiveRemoval("ABCCBCBA",strlen("ABCCBCBA"));

	/*MaximumOccuringCharacter("vivekanandaav",13);*/

	/*char str[] = "samplestritntg";
	printf("%c", getMaxOccuringChar(str));*/

	//char input1[] = "pVivekanandvi";
	//char input2[] = "Vivek";
	//RemoveCharsfromFirstString(input1, strlen(input1), input2, strlen(input2));

	//ReverseRecursion(input2, 0, strlen(input2) - 1);
	//reverse(input2);

	/*char str[] = "89789";
	int val = myAtoi(str);
	printf("%d ", val);*/
	char input123[] = "babbcdbb";
	RemovalOfbandac(input123, strlen(input123));
	getchar();
	return 0;
}



