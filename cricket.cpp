#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

string toLower(string s){                 //function to convert string to lowercase
    for(int i = 0;i<s.length();i++){
        s[i] = tolower(s[i]);            //convert each character to lowercase
    }
    return s;
}

//function to simulate innings for a team
int playInnings(string teamName,int overs,int target=-1){
    int score = 0;
    int balls = 0;
    int totalBalls = overs * 6;             //total legal balls in innings
    cout<<"\n====== "<<teamName<<"'s Innings Start =====\n";
    while(balls<totalBalls){
        int outcome = rand() % 10;          //random value between 0 and 9
        int over = balls / 6 + 1;           //calculate overs
        int ballInOver = balls % 6 + 1;     //show ball number(1.2,2.3)
        cout<<"Ball "<<over<< "."<<ballInOver<<": ";
        if(outcome == 0){                   //out=innings end 
            cout<<"OUT!\n";
            break;                         //wicket ends the innings
        } 
        else if(outcome == 5 || outcome == 7 || outcome == 8 || outcome == 9){
            cout<<"Wide Ball! +1 run\n";     //wide ball means +1
            score += 1;
            continue;                        //do not count as ball
        }
        else{
            cout<<outcome<<" run(s)"<<endl;
            score+= outcome;
            balls++;        //count ball
        }

        //check if over is completed
        if(balls%6==0){
            cout<<"End of over"<<over<<".Score:"<<score<<"/0\n";
        }
        //check if second team has beaten the target
        if (target!=-1 && score>target){
            cout<<"Target chased!\n";
            break;         
        }
    }
        //end of innings
    cout<<"Innings Ended. Final Score by "<<teamName<<": "<<score<<endl;
    return score;
}

int main(){
    srand(time(0));  //for random number
    string team1, team2;
    int overs;
    cout<<"\n\n=====* Welcome to the Virtual Cricket Game! *=====\n\n";
    //input number of overs with validation
    do{
        cout<<"Enter number of overs (1 to 5): ";
        cin>>overs;
        if(overs < 1 || overs > 5){
            cout<<"Invalid input! Please enter a number between 1 and 5:\n";
        }
    } while(overs < 1 || overs > 5);

    //input team names
    cout<<"Enter name of 1st team: ";
    cin>>team1;
    cout<<"Enter name of 2nd team: ";
    cin>>team2;
    while(team1==team2){           //input validation for different team names
        cout<<"its same as team 1"<<endl;
        cout<<"enter another name:";
        cin>>team2;
    }
    //toss input validation
    string tossCall;
    do{
        cout<<team1<<" choose Heads or Tails: ";
        cin>>tossCall;
        tossCall = toLower(tossCall);    //convert to lowercase for comparison
        if (tossCall != "heads" && tossCall != "tails"){
            cout<<"Invalid input! Please type Heads or Tails.\n";
        }
    } while(tossCall != "heads" && tossCall != "tails");

    string tossResult;
    int tossNumber = rand() % 2;      //random toss result 0=heads,1=tails
    if(tossNumber == 0){
        tossResult = "heads";
    }
    else{
        tossResult = "tails";
    }
    cout<<"Toss result: "<<tossResult<<endl;

    //decide toss winner
    string tossWinner;
    string tossLoser;
    if(tossCall == tossResult){
        tossWinner = team1;
        tossLoser = team2;
    }
    else{
        tossWinner = team2;
        tossLoser = team1;
    }
    cout<<"\t~"<<tossWinner<<" won the toss"<<"~\n";

    //toss winner chooses bat or ball
    string choice;
    do{
        cout<<tossWinner<<" choose to bat or ball: ";
        cin>>choice;
        choice = toLower(choice);       //convert to lowercase
        if(choice != "bat" && choice != "ball"){
            cout<<"Invalid choice! Please type bat or ball.\n";
        }
    } while(choice != "bat" && choice != "ball");

    //decide batting order
    string battingFirst, battingSecond;
    if(choice == "bat"){
        battingFirst = tossWinner;
        battingSecond = tossLoser;
    }
    else{
        battingFirst = tossLoser;
        battingSecond = tossWinner;
    }
    //first innings
    int score1 = playInnings(battingFirst, overs);
    //second innings
    int score2 = playInnings(battingSecond, overs, score1);
    //final result
    cout<<"\n----- MATCH RESULT-----\n";
    cout<<battingFirst<<": "<<score1<<endl;
    cout<<battingSecond<< ": "<<score2<<endl;

    if(score2 > score1)
        cout<<battingSecond<<" wins the match!\n";
    else if(score2 < score1) 
        cout<<battingFirst<<" wins the match!\n";
    else 
        cout<<"The match is a draw!\n";
    return 0; 

}