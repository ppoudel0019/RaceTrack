#include <iostream>
#include <fstream>
#include "car.h"

using namespace std;
char menu();
int main()

{
    fstream fin,fout,fout1;
    fin.open("racetrack_data.txt", ios::in);
    int N,l,s;
    string snum,fname,sid;
      string base="output";


    fout1.open("command.txt");
    fout1<<"set xrange [0:80]"<<endl;
    fout1<<"set yrange [0:80]"<<endl;
    fout1<<"set terminal png size 1000,800 "<<endl;
    fout1<<"set output 'track.png'"<<endl;

string pngfile;  ///name of the pictures
string target2;
    car * previous = NULL;
    car * curr = NULL;



char option = 'Z'; /// Z is not in the menu
while(option!='Q') //Q is quit
    {
    option=menu();
     switch(option)
        {

     case 'R':{

      cout<<"how many cars?(MAXIMUM:5) "<<endl;
      cin>>N;

      cout<<"how many laps?"<<endl;
      cin>>l;
        default_random_engine*gptr;
        gptr=new default_random_engine(time(NULL));
        for(int i=0; i<N; i++)
        {
        if(previous==NULL){previous = new car;
                     previous->setID(i+1);

                     previous->racetrack(gptr,l);}  ///occurs only ONCE
        else{
            curr=new car; //make a new car
            curr->setID(i+1);


            curr->racetrack(gptr,l);
             //set the new cars ID
            curr->setNext(previous);
            previous = curr;
            }
        }

    ///  input file streams
  fstream fin0,fin1,fin2,fin3,fin4;
  fin0.open("car1.txt",ios::in);
  fin1.open("car2.txt",ios::in);
  fin2.open("car3.txt",ios::in);
  fin3.open("car4.txt",ios::in);
  fin4.open("car5.txt",ios::in);


double x0,y0,x1,y1,x2,y2,x3,y3,x4,y4;
///-------------merging data
fstream fout2;
int  num = 1;
for(int i=0; i<25; i++)
  {   snum=to_string(num);
      fin0>>x0>>y0;
      fin1>>x1>>y1;
      fin2>>x2>>y2;
      fin3>>x3>>y3;
      fin4>>x4>>y4;

      fname = base+snum+".txt";
      fout2.open(fname.c_str(),ios::out);
      fout2<<x0<<" "<<y0<<endl;
      fout2<<x1<<" "<<y1<<endl;
      fout2<<x2<<" "<<y2<<endl;
      fout2<<x3<<" "<<y3<<endl;
      fout2<<x4<<" "<<y4<<endl;

      fout2.close();
      num++;
      pngfile=snum+base+".png";  /// png files numbered output0 to...

    fout1<<"set output \'"<<pngfile<<"\'"<<endl;
    fout1<<"plot \'racetrack_data.txt\' with linespoints,\'"<<fname<<"\' with circles linecolor rgb \"#ff8000\" fill solid noborder"<<endl;

  }
// fout1<<"pause -1"<<endl;
 system("gnuplot command.txt");
 fout1.close();
 fout2.close();
 fin0.close();
 fin1.close();
 fin2.close();
 fin3.close();
 fin4.close();

 system("gnuplot command.txt");
     }

          case 'Q':{cout<<"Thank you.BYE!"<<endl;}break;

       }
   }


 return 0;

}

char menu()
{
    cout<<"Please enter option"<<endl;
    cout<<"R-- CAR RACE"<<endl;
    cout<<"Q -- quit"<<endl;
    char option;
    cin>>option;
    return option;
}

