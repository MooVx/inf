
#include "puzzle.h"


Puzzle::Puzzle( char answ[], char init[] ){
    for(unsigned int i=0; i<strlen(answ);i++)
        _solution.insert(answ[i]);
    for(unsigned int i=0; i<strlen(init);i++)
        _puzzle.insert(init[i]);
}

void Puzzle::display(){
    cout<<endl;
    if(_puzzle.isEmpty())
        cout<< "**brak napisu**"<<endl;
    else
        _puzzle.print();
    cout << endl;
}

bool Puzzle::isSolved(){
    if(_solution==_puzzle)
        return true;
    return false;
}

void Puzzle::cmd(){
    try {
        char kom[3];
        cout<<"co chcesz zrobić ?" <<endl;
        cin.getline(kom,3);
        if(kom[0]=='+')
            _puzzle.insert(kom[1]);
        else if(kom[0]=='-')
            _puzzle.remove();
        else if(kom[0]=='=')
            _puzzle.replace(kom[1]);
        else if(kom[0]=='N')
            _puzzle.gotoNext();
        else if(kom[0]=='P')
            _puzzle.gotoPrev();
        else if(kom[0]=='<')
            _puzzle.gotoBegin();
        else if(kom[0]=='>')
            _puzzle.gotoEnd();
        else if(kom[0]=='C')
            _puzzle.clear();
        else{
            cout<< "komenda nie rozpoznana!! \n kończe program."<<endl;
            exit(0);
        } 
	}
	catch (exception& ba){
		cerr << "logic_error Puzzle.cmd(): " << ba.what() << endl;
        sleep(2);
		exit(1);
	}	


}