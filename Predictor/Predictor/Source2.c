#include <stdio.h>
#include <string.h>
#include <math.h>


 int ArrayCheck(char,char);

 int ArrayCheck(char x[],char y[])
	{
		int h=0;
		int count=0;
		
		


		while (h<8)
		{
			if (x[h]==y[h])
			{
				count++;
			}
			h++;

		}
		
			if (count==8)
			{
				return 1;
			}	
			else 
			{
				return 0;
				}
		

	}

int main()
{

	int i;
	int counter=0;
	int counterL=0;
	char c;
	char Arr1[8];
	char Arr2[8];
	char Arr3[8];
	int check=0;
	int action;
	int action2;
	int prediction=1;
	int predictioncounter=0;
	int correctP=0;
	int q;
	int prediction1=1;
	int prediction2=1;
	int cP=0;
	int branch=0;
	int j=0;
	
	
	FILE *input_file;
	FILE *output_file;

	input_file=fopen("input.txt","r");
	output_file=fopen("exodos.txt","w");


	while ((c=fgetc(input_file))!=EOF)
	
	{
		if ((check==0)&&(c!='\n'))
		
			{
				Arr1[counter]=c;
				counter++;
				
			}
			
		
		if ((check==1)&&(c!='\n'))
		
			{
				
				Arr2[counter]=c;
				counter++;
			}
		

		
		if ((c=='\n')&&(check==1))
			{

				action=ArrayCheck(Arr1,Arr2);   

				

				
			
 

				/*************************************************************2 bit predictor******************/


			if (j=1)
			{
						if (prediction1!=action2)
						{
							if (prediction2!=action)
							{
								printf("Not taken2");
								if (prediction2==1)
									{prediction2=0;}
								else
									{prediction2=1;}
							}else
								{printf("Taken2");
									cP++;}
							
						}
				
				

				
				prediction1=prediction2;
			
	
			}
			j=1; 
			action2=action;	
			
			/********1-bit predictor*************/
	
		if (action==prediction)
				{
					printf("          Taken \n");
					correctP++;						//metrisi twn swstwn provlepsewn
					predictioncounter++;			// line 54 + 63 metrisi sinolikwn provlepsewn
				}
				else
				{
					printf("          Not Taken\n ");
					predictioncounter++;

					if (prediction==1)
					{
					prediction=0;
					}
					else 
					{
						prediction=1;
					}
				}


	
				//****************************Allagi pinakwn
				
				for (q=0;q<8;q++)
				{
					Arr1[q]=Arr2[q];
				}

				//******************************

				
				


			
		

				/************************************/
	


			
				
			counter=0;
			counterL++;
			check=1;
			
			}

		if ((c=='\n')&& (check==0))
			{
				counter=0;
				check=1;
			}
		
	}
	
	
	
	fprintf(output_file," Correct 1-bit predictions of total predictions %d/%d ",correctP,predictioncounter);
	fprintf(output_file,"\n Correcct 2-bit predictions of total predictions %d/%d ",cP,predictioncounter);
	fprintf(output_file,"\n Number of loops:%d",branch); 
	

		system("PAUSE");
		fclose(input_file);
		fclose(output_file);
		return 0;

	
}
	



