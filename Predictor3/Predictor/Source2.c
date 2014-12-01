#include <stdio.h>
#include <string.h>
#include <math.h>


int yeh_pat[32][3]={{3,0,0},{3,0,0},{3,0,0},{3,0,0},
					{3,0,0},{3,0,0},{3,0,0},{3,0,0},
					{3,0,0},{3,0,0},{3,0,0},{3,0,0},
					{3,0,0},{3,0,0},{3,0,0},{3,0,0},
					{3,0,0},{3,0,0},{3,0,0},{3,0,0},
					{3,0,0},{3,0,0},{3,0,0},{3,0,0},
					{3,0,0},{3,0,0},{3,0,0},{3,0,0},
					{3,0,0},{3,0,0},{3,0,0},{3,0,0}};

int diktis[5]={0,0,0,0,0};



	FILE *input_file;
	FILE *OneBit;
	FILE *TwoBit;
	FILE *Correlated;
	FILE *yeeh_Paat;
	FILE *tournament;
	FILE *ALLRESULTS;



	void Yehprint();

 void Yehprint()
 {
	 int var;
	 int var1;
	 
	 


	
	fprintf(yeeh_Paat," CS    | #Hits    | #Miss   |\n");

	for(var=0;var<32;var++)
	{	
		fprintf(yeeh_Paat,"-----------------------------\n");
		fprintf(yeeh_Paat,"   %d   |",yeh_pat[var][0]);
		for (var1=1;var1<3;var1++)
		{
			fprintf(yeeh_Paat,"   %d  |",yeh_pat[var][var1]);
		}
		fprintf(yeeh_Paat,"\n");
	}


 }



 void Yeeh_Pat(int);

void Yeeh_Pat(int action)
{
	int sum=0;
	sum = pow(2.0,0)*diktis[0];
	sum = sum + pow(2.0,1)*diktis[1];
	sum= sum + pow(2.0,2)*diktis[2];
	sum= sum + pow(2.0,3)*diktis[3];
	sum= sum + pow(2.0,4)*diktis[4];

	if(action==1)
	{
		yeh_pat[sum][1]=yeh_pat[sum][1]+1;
	
		if(yeh_pat[sum][0]==3)
		{
			yeh_pat[sum][0]= 3;
		}
		else if (yeh_pat[sum][0]==2)
		{
			yeh_pat[sum][0]= 3;
		}
		else if(yeh_pat[sum][0]==1)
		{
			yeh_pat[sum][0]= 2;
		}
		else if(yeh_pat[sum][0]==0)
		{
			yeh_pat[sum][0]= 1;
		}
	}
	
	if(action==0)
	{
		yeh_pat[sum][2]=yeh_pat[sum][2]+1;
		
		if(yeh_pat[sum][0]==3)
		{
			yeh_pat[sum][0]= 2;
		}
		else if(yeh_pat[sum][0]==2)
		{
			yeh_pat[sum][0]= 1;
		}
		else if(yeh_pat[sum][0]==1)
		{
			yeh_pat[sum][0]= 0;
		}
		else if(yeh_pat[sum][0]==0)
		{
			yeh_pat[sum][0]= 0;
		}
	}
}




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


 void Correlate(int,int,char[],int);

 void Correlate(int T,int NT,char pin1[],int F_Action,int g)
 {
	 if(g==1)
	 {
		int h=0;
		printf("Address : ");
	
		while(h<8)
		{
			printf("%c",pin1[h]);
			 h++;
		 }
	}
	 printf("\n");
	 if ((F_Action==1)&&(g==1))
	 {
		 printf("Action is TAKEN\n");
	 }
	 else if((F_Action==0)&&(g==1))
	 {
		 printf("Action is NOT TAKEN\n");
	 }


	 if ((T==1)&&(g==1))
	 {
		 printf("Correlated Predictor 1 : Taken\n");
	 }else if((T==0)&&(g==1))
	 {
		 printf("Correlated Predictor 1 : Not Taken\n");
	 }

	 if((NT==1)&&(g==1))
	 {
	 printf("Correlated Predictor 2 : Taken");

	 }else if ((NT==0)&&(g==1))
	 {
		 printf("Correlated Predictor 2 : Not Taken");
	 }
	 if(g==1)
	 {
	printf("\n");
	printf("\n");
    printf("\n");
	 }
 }

int main(){

	int tournamentCheck=0;
	int tournamentWrong=0;
	int tournamentHits=0;
	int ja=0;
	int w=0;
	int Wrong1C=0;
	int Right=0;
	int SelectedP=1;                    //gia timi 1 epilegmenos o prediction Taken gia timi 0 epilegmenos o not Taken 
	int predictionT=1;
	int predictionNT=1;
	int real=1;
	int i;
	int innerCheck=0;
	int counter=0;
	int counterL=0;
	char c;
	char Arr1[8];
	char Arr2[8];
	char Arr3[8];
	int check=0;
	int z=0;
	int j=0;
	int d=0;
	int x=0;
	int k=0;
	int action=0;
	int action3=0;
	int action2=0;
	int pointer=0;
	int outer=0;
	int inner=0;
	int prediction=1;
	int wrong1=0;
	int correctP=0;
	int prediction2=1;
	int Correct2B=0;
	int wrong2=0;
	int Counter2B=0;
	input_file=fopen("input.txt","r");
	OneBit=fopen("1Bitresults.txt","w");
	TwoBit=fopen("2Bitresults.txt","w");
	Correlated=fopen("Correlated.txt","w");
	yeeh_Paat=fopen("Yeh_pat.txt","w");
	tournament=fopen("TournamentResults.txt","w");
	ALLRESULTS=fopen("AllpredictorsResults.txt","w");

	printf("Correlate prediction 1: Taken \nCorrelate prediction 2: Taken\n\n");
	
	
	printf("Press 1 to print the results of the Correlated 1.1 predictor in the terminal or 0 to not print the result in the terminal\n");
	scanf("%d",&w);

	if(w==1)

	{
		printf("Correlate prediction 1: Taken \nCorrelate prediction 2: Taken\n\n");
	}


	while ((c=fgetc(input_file))!=EOF)
	
	{
		if(c!='a'&&c!='b'&&c!='c'&&c!='d'&&c!='e'&&c!='f'&&c!='A'&&c!='B'&&c!='C'&&c!='D'&&c!='E'&&c!='F'&&c!='0'&&c!='1'&&c!='2'&&c!='3'&&c!='4'&&c!='5'&&c!='6'&&c!='7'&&c!='8'&&c!='9'&&c!='\n')
		{
			printf("Error Character, Check input file\n");
			system("PAUSE");
			return 0;
		}
		pointer=-1;
	
		if ((check==0)&&(c!='\n'))
		
			{
				Arr1[counter]=c;	
				
			}
			
		
		if ((check==1)&&(c!='\n'))
		
			{
				
				Arr2[counter]=c;
				
				
			}
		if ((check==2)&&(c!='\n'))
			{
				Arr3[counter]=c;
				
				
			}

		if ((check==2)&&(c=='\n'))
		{
		action2=ArrayCheck(Arr1,Arr3);
		action3=ArrayCheck(Arr2,Arr3);
		
		pointer=2;
		
		}

		if ((check==1)&&(c=='\n'))
		{
			action=ArrayCheck(Arr1,Arr2);
			
		pointer=1;
		}

		if ((check==0)&&(c=='\n')){
		pointer=0;
		}

		if(pointer==0){
			
		check=1;
		}

		if(pointer==1){
			if(action==0)
		{
				if (prediction==1){
				wrong1++;
				prediction=0;
				if(tournamentCheck==0)
					{tournamentWrong++;}


				}
				else if(prediction==0)
				{correctP++;
				
					if(tournamentCheck==0)
					{  
						tournamentHits++;
						if(tournamentWrong==0)
						{tournamentWrong=0;}
						else if(tournamentWrong==1)
						{tournamentWrong=0;}
					}
				
				
				}

				if (prediction2==1){
				wrong2++;
				Counter2B++;
			}
			else if  (prediction2==0){
				Correct2B++;
				
			}

			if ((Counter2B==2)&&(prediction2==1)){
				prediction2=0;
				Counter2B=0;
			}
			else if ((Counter2B==2)&&(prediction2==0)){
			prediction2=1;
			Counter2B=0;
			}

			Correlate(predictionT,predictionNT,Arr1,action,w);/////////////


			if (SelectedP==1)
			{
				if(predictionT==1)
				{ Wrong1C++;
					predictionT=0;
					SelectedP=0;

					if(tournamentCheck==1)
						{tournamentWrong++;}


				}
				else if(predictionT==0)
				{
					predictionT=0;
					Right++;


					if(tournamentCheck==1)
					{  
						tournamentHits++;
						if(tournamentWrong==0)
						{tournamentWrong=0;}
						else if(tournamentWrong==1)
						{tournamentWrong=0;}
					}


				}

			}else if (SelectedP==0)
				{
					if(predictionNT==1)
					{predictionNT=0;
					Wrong1C++;
					SelectedP=1;

					if(tournamentCheck==1)
						{tournamentWrong++;}



					}
					else if(predictionNT==0)
					{
						Right++;

						if(tournamentCheck==1)
							{  
								tournamentHits++;
								if(tournamentWrong==0)
								{tournamentWrong=0;}
								else if(tournamentWrong==1)
								{tournamentWrong=0;}
							}


					}
				}

			//printf("Not Taken\n");
			check=2;

			Yeeh_Pat(action);

			for(ja=0;ja<5;ja++) 
			{
				diktis[ja]=diktis[ja+1];
			}
				diktis[4]=action;



		}


			else if (action==1)
			{
		
				
				
				check=1;
			if (prediction==1)
				{
					correctP++;
				
						if(tournamentCheck==0)
						{  
							tournamentHits++;
							if(tournamentWrong==0)
							{tournamentWrong=0;}
							else if(tournamentWrong==1)
							{tournamentWrong=0;}
						}


				}
				else if(prediction==0)
				{
					wrong1++;
					prediction=0;
			
					if(tournamentCheck==0)
						{tournamentWrong++;}
			
				}


			if (prediction2==1){
				Correct2B++;
			}
			else if  (prediction2==0){
				wrong2++;
				Counter2B++;
			}

			if ((Counter2B==2)&&(prediction2==1)){
				prediction2=0;
				Counter2B=0;
			}
			else if ((Counter2B==2)&&(prediction2==0)){
			prediction2=1;
			Counter2B=0;
			}
			
			Correlate(predictionT,predictionNT,Arr1,action,w);


			if (SelectedP==1)
			{
				if(predictionT==1)
				{ Right++;
				
					if(tournamentCheck==1)
					{  
						tournamentHits++;
						if(tournamentWrong==0)
						{tournamentWrong=0;}
						else if(tournamentWrong==1)
						{tournamentWrong=0;}
					}

				}
				else if(predictionT==0)
				{
				predictionT=1;
				SelectedP=0;
				Wrong1C++;


					if(tournamentCheck==1)
						{tournamentWrong++;}


				}

			}else if (SelectedP==0)
				{
					if(predictionNT==1)
					{predictionNT=1;
					Right++;
					
						if(tournamentCheck==1)
							{  
							tournamentHits++;
							if(tournamentWrong==0)
							{tournamentWrong=0;}
							else if(tournamentWrong==1)
							{tournamentWrong=0;}
							}



					}
					else if(predictionNT==0)
					{
					predictionNT=1;
					SelectedP=1;
					Wrong1C++;

					if(tournamentCheck==1)
						{tournamentWrong++;}


					}
			}


			//printf("Taken\n");
			outer++;



			Yeeh_Pat(action);

			for(ja=0;ja<5;ja++) 
			{
				diktis[ja]=diktis[ja+1];
			}
				diktis[4]=action;



			}

			
		}

		if(pointer==2)
		{

		if (action2==1)
		{
			
			while(z<8)
				{
					Arr1[z]=Arr2[z];
				z++;
				}
		z=0;
		while(z<8)
				{
					Arr2[z]=Arr3[z];
				z++;
				}
			if (prediction==1)
			{
				correctP++;
		
				if(tournamentCheck==0)
				{  
						tournamentHits++;
						if(tournamentWrong==0)
						{tournamentWrong=0;}
						else if(tournamentWrong==1)
						{tournamentWrong=0;}
                }


			}
				else if(prediction==0)
				{
					wrong1++;
					prediction=0;
			
						if(tournamentCheck==0)
							{tournamentWrong++;}

				}


		if (prediction2==1){
				Correct2B++;
			}
			else if  (prediction2==0){
				wrong2++;
				Counter2B++;
			}

			if ((Counter2B==2)&&(prediction2==1)){
				prediction2=0;
				Counter2B=0;
			}
			else if ((Counter2B==2)&&(prediction2==0)){
			prediction2=1;
			Counter2B=0;
			}

			Correlate(predictionT,predictionNT,Arr1,action2,w);


			if (SelectedP==1)
			{
				if(predictionT==1)
				{ Right++;
				
				
						if(tournamentCheck==1)
							{  
							tournamentHits++;
							if(tournamentWrong==0)
							{tournamentWrong=0;}
							else if(tournamentWrong==1)
							{tournamentWrong=0;}
							}

				}
				else if(predictionT==0)
				{
				predictionT=1;
				SelectedP=0;
				Wrong1C++;

				if(tournamentCheck==1)
					{tournamentWrong++;}


				}

			}else if (SelectedP==0)
				{
					if(predictionNT==1)
					{
						predictionNT=1;
						Right++;
	
						if(tournamentCheck==1)
							{  
								tournamentHits++;
								if(tournamentWrong==0)
								{tournamentWrong=0;}
								else if(tournamentWrong==1)
								{tournamentWrong=0;}
							}
					}
					else if(predictionNT==0)
					{
					predictionNT=1;
					SelectedP=1;
					Wrong1C++;

						if(tournamentCheck==1)
							{tournamentWrong++;}


					}
			}

			//printf("Taken\n");
		    outer++;
		    
			check=2;



			Yeeh_Pat(action2);

			for(ja=0;ja<5;ja++) 
			{
				diktis[ja]=diktis[ja+1];
			}
				diktis[4]=action2;



		}
		else if (action3==1)
		{
			

			if (prediction==1)
			{
				correctP++;
						
				if(tournamentCheck==0)
				{  
					tournamentHits++;
					if(tournamentWrong==0)
					{tournamentWrong=0;}
					else if(tournamentWrong==1)
					{tournamentWrong=0;}
                }



			}
				else if(prediction==0)
				{
					
					wrong1++;
					prediction=0;
			
				if(tournamentCheck==0)
					{tournamentWrong++;}
						
			
			
			
				}


			if (prediction2==1){
				Correct2B++;
			}
			else if  (prediction2==0){
				wrong2++;
				Counter2B++;
			}

			if ((Counter2B==2)&&(prediction2==1)){
				prediction2=0;
				Counter2B=0;
			}
			else if ((Counter2B==2)&&(prediction2==0)){
			prediction2=1;
			Counter2B=0;
			}

			Correlate(predictionT,predictionNT,Arr2,action3,w);


			if (SelectedP==1)
			{
				if(predictionT==1)
				{ Right++;

				if(tournamentCheck==1)
				{  
								tournamentHits++;
								if(tournamentWrong==0)
								{tournamentWrong=0;}
								else if(tournamentWrong==1)
								{tournamentWrong=0;}
                }
				
				}else if(predictionT==0)
				{
				predictionT=1;
				SelectedP=0;
				Wrong1C++;

					if(tournamentCheck==1)
						{tournamentWrong++;}

				}

			}else if (SelectedP==0)
				{
					if(predictionNT==1)
					{
						
						predictionNT=1;
						Right++;

						if(tournamentCheck==1)
							{  
								tournamentHits++;
								if(tournamentWrong==0)
								{tournamentWrong=0;}
								else if(tournamentWrong==1)
								{tournamentWrong=0;}
							}
					}
					else if(predictionNT==0)
					{
					predictionNT=1;
					SelectedP=1;
					Wrong1C++;

						if(tournamentCheck==1)
						{tournamentWrong++;}


					}
			}

			//printf("Taken\n");
			check=2;
			inner++;


			Yeeh_Pat(action3);

			for(ja=0;ja<5;ja++) 
			{
				diktis[ja]=diktis[ja+1];
			}
				diktis[4]=action3;
			
				
			
		}
		else
		{
		while(z<8)
				{
					Arr1[z]=Arr2[z];
				z++;
				}
		z=0;
		while(z<8)
				{
					Arr2[z]=Arr3[z];
				z++;
				}
		
		if (prediction==1){
				wrong1++;
				prediction=0;


				if(tournamentCheck==0)
					{tournamentWrong++;}


				}
				else if(prediction==0)
				{
					
					correctP++;
					if(tournamentCheck==0)
						{  
						tournamentHits++;
						if(tournamentWrong==0)
						{tournamentWrong=0;}
						else if(tournamentWrong==1)
						{tournamentWrong=0;}
						}
		
		
		
				}

		if (prediction2==1){
				wrong2++;
				Counter2B++;
			}
			else if  (prediction2==0){
				Correct2B++;
				
			}

			if ((Counter2B==2)&&(prediction2==1)){
				prediction2=0;
				Counter2B=0;
			}
			else if ((Counter2B==2)&&(prediction2==0)){
			prediction2=1;
			Counter2B=0;
			}

			Correlate(predictionT,predictionNT,Arr1,action3,w);/////////////


			if (SelectedP==1)
			{
				if(predictionT==1)
				{ Wrong1C++;
					predictionT=0;
					SelectedP=0;


					if(tournamentCheck==1)
							{tournamentWrong++;}



				}
				else if(predictionT==0)
				{
					predictionT=0;
					Right++;


					if(tournamentCheck==1)
						{  
						tournamentHits++;
						if(tournamentWrong==0)
							{tournamentWrong=0;}
						else if(tournamentWrong==1)
							{tournamentWrong=0;}
						}	


				}

			}else if (SelectedP==0)
				{
					if(predictionNT==1)
					{predictionNT=0;
					Wrong1C++;
					SelectedP=1;

					if(tournamentCheck==1)
							{tournamentWrong++;}



					}
					else if(predictionNT==0)
					{
					Right++;


					if(tournamentCheck==1)
						{  
						tournamentHits++;
						if(tournamentWrong==0)
							{tournamentWrong=0;}
						else if(tournamentWrong==1)
							{tournamentWrong=0;}
						}	



					}
				}


		//printf("Not Taken\n");
		check=2;




		Yeeh_Pat(0);

			for(ja=0;ja<5;ja++) 
			{
				diktis[ja]=diktis[ja+1];
			}
				diktis[4]=0;
		}
		
		
		}

		counter++;
		if(c=='\n')
		{
		counter=0;

			if(tournamentCheck==0)
			{
				fprintf(tournament,"1-bit Predictor is selected\n");
			}else if(tournamentCheck==1)
			{
				fprintf(tournament,"Correlated predictor is selected\n");
			}

			if(tournamentWrong==2)
			{
				
				if(tournamentCheck==0)
				{tournamentCheck=1;}
				else if(tournamentCheck==1)
				{tournamentCheck=0;}

				tournamentWrong==0;
			}

		
		}
		
	}
	

	printf("Total Loops: %d\n",outer+inner);
	printf("outer %d\n",outer);
	printf("inner %d\n",inner);


	printf("\nCorrect prediction of 1-bit: %d/%d\n",correctP,correctP+wrong1);
	printf("Wrong prediction of 1-bit:   %d\n",wrong1);
	

	printf("\nCorrect prediction of 2-bit : %d/%d\n",Correct2B,Correct2B+wrong2);
	printf("Wrong prediction of 2-bit :   %d\n\n",wrong2);
	

	printf("Correct predictions of 1.1 Correlate predictor  out of total: %d/%d\n\n",Right,Right+Wrong1C); 
	
	fprintf(OneBit,"Correct predictions of 1-bit out of total: %d/%d\n",correctP,correctP+wrong1);
	fprintf(TwoBit,"Correct predictions of 2-bit out of total: %d/%d\n",Correct2B,Correct2B+wrong2);
	fprintf(Correlated,"Correct predictions of 1.1 Correlate predictor  out of total: %d/%d",Right,Right+Wrong1C);
	fprintf(tournament,"Hits from tournament %d    ",tournamentHits);



	fprintf(ALLRESULTS,"Correct predictions of 1-bit out of total: %d/%d\n\n",correctP,correctP+wrong1);
	fprintf(ALLRESULTS,"Correct predictions of 2-bit out of total: %d/%d\n\n",Correct2B,Correct2B+wrong2);
	fprintf(ALLRESULTS,"Correct predictions of 1.1 Correlate predictor  out of total: %d/%d\n\n",Right,Right+Wrong1C);
	fprintf(ALLRESULTS,"Hits from tournament %d    ",tournamentHits);


	Yehprint();

	
		fclose(input_file);
		fclose(OneBit);
		fclose(TwoBit);
		fclose(Correlated);
		system("pause");
		return 0;
		
	
}
 
