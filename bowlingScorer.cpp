#include <iostream>


size_t scores[11];
bool strikes[11];

void printScore(size_t frame){
    size_t total = 0;
    for(size_t i=1;i<=frame;++i){
        total += scores[i];
    }
    std::cout<< "Total is "<<total<<" points"<<std::endl;
}

void setScore(size_t roll1, size_t roll2,size_t roll3,size_t frame){

    size_t total = roll1+roll2;
    if(frame!=10) {
        if (total > 10) { throw std::invalid_argument("Frame total can't be greater than 10"); }
        if (roll1 == 10) {
            scores[frame] = 10;
            strikes[frame] = true;
        } else { scores[frame] = total; }
        if(scores[frame-1]==10){scores[frame-1]+=roll1;}
        if (strikes[frame - 1] && strikes[frame - 2]) {
            scores[frame - 2] = 20 + roll1;
        }
        if (strikes[frame - 1]) { scores[frame - 1] = 10 + roll1 + roll2; }
    }
    else{

        if(roll1==10){scores[10]=10+roll2+roll3;}
        else if(total==10){scores[10]=total+roll3;}
        else{scores[10]= roll1+roll2;}
        if(scores[frame-1]==10){scores[frame-1]+=roll1;}
        if (strikes[frame - 1] && strikes[frame - 2]) {
            scores[frame - 2] = 20 + roll1;
        }
        if(strikes[frame - 1]) { scores[frame - 1] = 10 + roll1 + roll2; }

    }
}

int main() {

    size_t roll1;
    size_t roll2;
    size_t roll3 =0;
    for(size_t i=0;i<10;++i){
        strikes[i]=false;
    }


    for(size_t i=1;i<11;++i) {
        std::cout << "Enter frame " << i << " roll 1: " <<std::endl;
        std::cin>>roll1;
        roll2=0;
        if(roll1!=10||i==10) {
            std::cout << "Enter frame " << i << " roll 2: " << std::endl;
            std::cin >> roll2;
        }
        if(i==10&&roll1+roll2>=10){
            std::cout << "Enter frame " << i << " roll 3: " << std::endl;
            std::cin >> roll3;
        }
        setScore(roll1,roll2,roll3,i);
        printScore(i);
    }

    for(size_t i=1;i<11;++i){
        std::cout<<std::endl<<scores[i];
    }
}
