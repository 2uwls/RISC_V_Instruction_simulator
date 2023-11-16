#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disassembler.h"
#include "calculate.h"
#include "simulator.h"

//convert input to binary : [31]~~~[0]
void fill_binary_arr(unsigned int value, int binary_arr[32])
{
    for(int i=31; i>=0; i--)
    {
        binary_arr[i]=(value>>i)&1;
    }
}

//address calculate
char* convert_binary_to_decimal(char* binary_string)
{
    int decimal=0;
    int length=strlen(binary_string);
    char* string_num=(char*)malloc(length+1);

    for(int i=0;i<length;i++)
    {
        if(binary_string[i]=='1')
            decimal+=1<<(length-1-i);
    }
    sprintf(string_num, "%d",decimal);
    return string_num;
}

//immediate calculate
char* convert_binary_to_decimal_imm(char* binary_string)
{
    int decimal=0;
    int length=strlen(binary_string);
    char* string_num=(char*)malloc(length+1);

    int complement_count=0;

   if(binary_string[0]=='1')
   {
        complement_count=1;
        for(int i=0; i<length; i++)
        {
            if(binary_string[i]=='0')
                binary_string[i]='1';
            else
                binary_string[i]='0';
        }
        int carry=1;
        for(int i= length-1; i>=0;i--)
        {
            if(binary_string[i]=='0'&&carry==1)
            {
                binary_string[i]='1';
                carry=0;
            }
            else if(binary_string[i]=='1'&&carry==1)
            {
                binary_string[i]='0';
            }
        }
   }
    for(int i=0;i<length;i++)
    {
        if(binary_string[i]=='1')
            decimal+=1<<(length-1-i);
    }

    if(complement_count)
        decimal=-decimal;
    sprintf(string_num, "%d",decimal);
    return string_num;
}

char* slice_array(int* arr, int start, int end)
{
    int arr_size = end-start;
    char* combined_num =(char *)malloc(sizeof(char)*(arr_size+1));
    int* sliced_array=(int *)malloc(sizeof(int)*arr_size);
    int num=0;
    
    for (int i = 0; i < arr_size; i++) {
        sliced_array[i] = arr[end - 1 - i];
    }

    for (int i=0; i<arr_size;i++)
    {
        char digit=sliced_array[i]+'0';
        combined_num[num++]=digit;
    }
    combined_num[num]='\0';

    return combined_num;
}

