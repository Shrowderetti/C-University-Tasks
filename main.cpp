//Adam Koziana
#include <iostream>
using namespace std;
int main() {
    //Variables input
    int numberOfRounds;
    char player1, player2;
    int round = 1;
    int r1, r2, r3, r4, r5, r6, r7, r8;
    r1=r2=r3=r4=r5=r6=r7=r8=1;
    //Variables rules
    double winA, winB, winC, winD, winE;
    double tieA, tieB, tieC, tieD, tieE;
    double defA, defB, defC, defD, defE;
    double numOfRoundsA, numOfRoundsB, numOfRoundsC, numOfRoundsD, numOfRoundsE;
    int winCon1, winCon2;
    winA = winB = winC = winD = winE = 0;
    tieA = tieB = tieC = tieD = tieE = 0;
    defA = defB = defC = defD = defE = 0;
    numOfRoundsA = numOfRoundsB = numOfRoundsC = numOfRoundsD = numOfRoundsE = 0;
    double winRateA, winRateB, winRateC, winRateD, winRateE;
    double defRateA, defRateB, defRateC, defRateD, defRateE;
    double tieRateA, tieRateB, tieRateC, tieRateD, tieRateE;
    //Variables resulting
    int player1sum, player2sum, player1addsum, player2addsum;
    //Start of poker code
    //Input values
    do {
        cin >> numberOfRounds;
    } while (numberOfRounds <= 0);
    while (round < (numberOfRounds + 1)) {
        //First player data
        do {
            cin >> player1;
        } while ((player1 != 'a') && (player1 != 'b') && (player1 != 'c') && (player1 != 'd') && (player1 != 'e'));
        do {
            cin >> r1 >> r2 >> r3 >> r4;

        } while ((r1 < 0 || r1 > 4) || (r2 < 0 || r2 > 4) || (r3 < 0 || r3 > 4) || (r4 < 0 || r4 > 4));
        //Second player data
        do {
            cin >> player2;

        } while ((player2 != 'a') && (player2 != 'b') && (player2 != 'c') && (player2 != 'd') && (player2 != 'e'));

        do {
            cin >> r5 >> r6 >> r7 >> r8;

        } while ((r5 < 0 || r5 > 4) || (r6 < 0 || r6 > 4) || (r7 < 0 || r7 > 4) || (r8 < 0 || r8 > 4));
        //Results player 1
        //4 of the same
        if ((r1==r2 && r1==r3 && r1==r4 && r2==r3 && r2==r4 && r3==r4)) {
            winCon1 = 5;
            //4 of the different
        }
        else if ((r1!=r2 && r1!=r3 && r1!=r4 && r2!=r3 && r2!=r4 && r3!=r4)) {
            winCon1 = 4;
        }
            //2 pairs
        else if ((r1==r2&&r3==r4)||(r1==r3&&r2==r4)||(r1==r4&&r2==r3)) {
            winCon1 = 3;
        }
            //3 of the same
        else if ((r1==r2&&r1==r3&&r2==r3) || (r1==r2&&r1==r4&&r2==r4) || (r1==r3&&r1==r4&&r3==r4) || (r2==r3&&r2==r4&&r3==r4)) {
            winCon1 = 2;
        }
            //1 pair
        else if ((r1 == r2 || r1 == r3 || r1 == r4 || r2 == r3 || r2 == r4 || r3 == r4)) {
            winCon1 = 1;
        }
        //Results of player 2
        //4 of the same
        if ((r5==r6 && r5==r7 && r5==r8 && r6==r7 && r6==r8 && r7==r8)) {
            winCon2 = 5;
        }
            //4 of the different
        else if ((r5!=r6 && r5!=r7 && r5!=r8 && r6!=r7 && r6!=r8 && r7!=r8)) {
            winCon2 = 4;
        }
            //2 pairs
        else if ((r5==r6&&r7==r8)||(r5==r7&&r6==r8)||(r5==r8&&r6==r7)) {
            winCon2 = 3;
        }
            //3 of the same
        else if ((r5==r6&&r5==r7&&r6==r7) || (r5==r6&&r5==r8&&r6==r8) || (r5==r7&&r5==r8&&r7==r8) || (r6==r7&&r6==r8&&r7==r8)) {
            winCon2 = 2;
        }
            //1 pair
        else if ((r5 == r6 || r5 == r7 || r5 == r8 || r6 == r7 || r6 == r8 || r7 == r8)) {
            winCon2 = 1;
        }
        //Points distribution
        //Both get tie
        if (winCon1 == winCon2) {
            //4 of the same tie
            if (winCon1==5&&winCon2==5) {
                if ((r1 + r2 + r3 + r4) > (r5 + r6 + r7 + r8)) {
                    winCon1 += 1;
                } else if ((r1 + r2 + r3 + r4) < (r5 + r6 + r7 + r8)) {
                    winCon2 += 1;
                }
            }
                //2 pairs tie
            else if (winCon1==3&&winCon2==3) {
                if (r1==r2&&r3==r4) {
                    if ((r1+r2)>(r3+r4)) {
                        player1sum=r1+r2;
                        player1addsum=r3+r4;
                    } else if ((r1+r2)<(r3+r4)) {
                        player1sum=r3+r4;
                        player1addsum=r1+r2;
                    }
                }
                else if (r1==r3&&r2==r4) {
                    if ((r1+r3)>(r2+r4)) {
                        player1sum=r1+r3;
                        player1addsum=r2+r4;
                    } else if ((r1+r3)<(r2+r4)) {
                        player1sum=r2+r4;
                        player1addsum=r1+r3;
                    }
                }
                else if (r1==r4&&r2==r3) {
                    if ((r1+r4)>(r2+r3)) {
                        player1sum=r1+r4;
                        player1addsum=r2+r3;
                    } else if ((r1+r4)<(r2+r3)) {
                        player1sum=r2+r3;
                        player1addsum=r1+r4;
                    }
                }
                if (r5==r6&&r7==r8) {
                    if ((r5+r6)>(r7+r8)) {
                        player2sum=r5+r6;
                        player2addsum=r7+r8;
                    } else if ((r5+r6)<(r7+r8)) {
                        player2sum=r7+r8;
                        player2addsum=r5+r6;
                    }
                }
                else if (r5==r7&&r6==r8) {
                    if ((r5+r7)>(r6+r8)) {
                        player2sum=r5+r7;
                        player2addsum=r6+r8;
                    } else if ((r5+r7)<(r6+r8)) {
                        player2sum=r6+r8;
                        player2addsum=r5+r7;
                    }
                }
                else if (r5==r8&&r6==r7) {
                    if ((r5+r8)>(r6+r7)) {
                        player2sum=r5+r8;
                        player2addsum=r6+r7;
                    } else if ((r5+r8)<(r6+r7)) {
                        player2sum=r6+r7;
                        player2addsum=r5+r8;
                    }
                }
                if (player1sum>player2sum) {
                    winCon1+=1;
                } else if (player1sum<player2sum) {
                    winCon2+=1;
                } else if (player1sum==player2sum) {
                    if (player1addsum>player2addsum) {
                        winCon1+=1;
                    } else if (player1addsum<player2addsum) {
                        winCon2 += 1;
                    } else if (player1addsum==player2addsum) {
                        if ((r1 + r2 + r3 + r4) > (r5 + r6 + r7 + r8)) {
                            winCon1 += 1;
                        } else if ((r1 + r2 + r3 + r4) < (r5 + r6 + r7 + r8)) {
                            winCon2 += 1;
                        }
                    }
                }
            }
                //3 of the same tie
            else if (winCon1==2&&winCon2==2) {
                if ((r1 == r2 && r1 == r3 && r2 == r3)) {
                    player1sum = r1 + r2 + r3;
                } else if ((r1 == r2 && r1 == r4 && r2 == r4)) {
                    player1sum = r1 + r2 + r4;
                } else if (r1 == r3 && r1 == r4 && r3 == r4) {
                    player1sum = r1 + r3 + r4;
                } else if (r2 == r3 && r2 == r4 && r3 == r4) {
                    player1sum = r2 + r3 + r4;
                }
                if (r5 == r6 && r5 == r7 && r6 == r7) {
                    player2sum = r5 + r6 + r7;
                } else if (r5 == r6 && r5 == r8 && r6 == r8) {
                    player2sum = r5 + r6 + r8;
                } else if (r5 == r7 && r5 == r8 && r7 == r8) {
                    player2sum = r5 + r7 + r8;
                } else if ((r6 == r7 && r6 == r8 && r7 == r8)) {
                    player2sum = r6 + r7 + r8;
                }
                if (player1sum > player2sum) {
                    winCon1 += 1;
                } else if (player1sum < player2sum) {
                    winCon2 += 1;
                } else if (player1sum==player2sum) {
                    if ((r1 + r2 + r3 + r4) > (r5 + r6 + r7 + r8)) {
                        winCon1 += 1;
                    } else if ((r1 + r2 + r3 + r4) < (r5 + r6 + r7 + r8)) {
                        winCon2 += 1;
                    }
                }
            }
                //1 pair tie
            else if (winCon1==1&&winCon2==1) {
                if (r1==r2) {
                    player1sum=r1+r2;
                } else if (r1==r3) {
                    player1sum=r1+r3;
                } else if (r1==r4) {
                    player1sum=r1+r4;
                } else if (r2==r3) {
                    player1sum=r2+r3;
                } else if (r2==r4) {
                    player1sum=r2+r4;
                } else if (r3==r4) {
                    player1sum=r3+r4;
                }
                if (r5==r6){
                    player2sum=r5+r6;
                } else if (r5==r7) {
                    player2sum=r5+r7;
                } else if (r5==r8) {
                    player2sum=r5+r8;
                } else if (r6==r7) {
                    player2sum=r6+r7;
                } else if (r6==r8) {
                    player2sum=r6+r8;
                } else if (r7==r8) {
                    player2sum=r7+r8;
                }
                if (player1sum>player2sum) {
                    winCon1+=1;
                } else if (player1sum<player2sum) {
                    winCon2+=1;
                } else if (player1sum==player2sum) {
                    if ((r1 + r2 + r3 + r4) > (r5 + r6 + r7 + r8)) {
                        winCon1 += 1;
                    } else if ((r1 + r2 + r3 + r4) < (r5 + r6 + r7 + r8)) {
                        winCon2 += 1;
                    }
                }
            }
            if (winCon1==winCon2) {
                if (player1 == 'a') {
                    tieA +=1;
                }
                if (player1 == 'b') {
                    tieB +=1;
                }
                if (player1 == 'c') {
                    tieC +=1;
                }
                if (player1 == 'd') {
                    tieD +=1;
                }
                if (player1 == 'e') {
                    tieE +=1;
                }
                if (player2 == 'a') {
                    tieA +=1;
                }
                if (player2 == 'b') {
                    tieB +=1;
                }
                if (player2 == 'c') {
                    tieC +=1;
                }
                if (player2 == 'd') {
                    tieD +=1;
                }
                if (player2 == 'e') {
                    tieE +=1;
                }
            }
        }
        //First one wins
        if (winCon1 > winCon2) {
            if (player1 == 'a') {
                winA +=1;
            } else if (player1 == 'b') {
                winB +=1;
            } else if (player1 == 'c') {
                winC +=1;
            } else if (player1 == 'd') {
                winD +=1;
            } else if (player1 == 'e') {
                winE +=1;
            }
        }
        //First one lose
        if (winCon1 < winCon2) {
            if (player1 == 'a') {
                defA +=1;
            } else if (player1 == 'b') {
                defB +=1;
            } else if (player1 == 'c') {
                defC +=1;
            } else if (player1 == 'd') {
                defD +=1;
            } else if (player1 == 'e') {
                defE +=1;
            }
        }
        //Second one wins
        if (winCon1 < winCon2) {
            if (player2 == 'a') {
                winA +=1;
            } else if (player2 == 'b') {
                winB +=1;
            } else if (player2 == 'c') {
                winC +=1;
            } else if (player2 == 'd') {
                winD +=1;
            } else if (player2 == 'e') {
                winE +=1;
            }
        }
        //Second one loses
        if (winCon1 > winCon2) {
            if (player2 == 'a') {
                defA +=1;
            } else if (player2 == 'b') {
                defB +=1;
            } else if (player2 == 'c') {
                defC +=1;
            } else if (player2 == 'd') {
                defD +=1;
            } else if (player2 == 'e') {
                defE +=1;
            }
        }
        //Counting rounds
        if ((player1 == 'a') || (player2 == 'a')) {
            numOfRoundsA += 1;
        }
        if ((player1 == 'b') || (player2 == 'b')) {
            numOfRoundsB += 1;
        }
        if ((player1 == 'c') || (player2 == 'c')) {
            numOfRoundsC += 1;
        }
        if ((player1 == 'd') || (player2 == 'd')) {
            numOfRoundsD += 1;
        }
        if ((player1 == 'e') || (player2 == 'e')) {
            numOfRoundsE += 1;
        }
        round += 1;
    }
    //Display of results
    winRateA = ((winA/numOfRoundsA)*100);
    defRateA = ((defA/numOfRoundsA)*100);
    tieRateA = ((tieA/numOfRoundsA)*100);
    if (numOfRoundsA > 0) {
        cout << "gracz a" << endl;
        if (winA > 0) {
            cout << "    wygrane: " << winRateA << "%" << endl;
        }
        if (tieA > 0) {
            cout << "    remisy: " << tieRateA << "%" << endl;
        }
        if (defA > 0) {
            cout << "    przegrane: " << defRateA << "%" << endl;
        }
        cout << endl;
    }
    winRateB = ((winB/numOfRoundsB)*100);
    defRateB = ((defB/numOfRoundsB)*100);
    tieRateB = ((tieB/numOfRoundsB)*100);
    if (numOfRoundsB > 0) {
        cout << "gracz b" << endl;
        if (winB > 0) {
            cout << "    wygrane: " << winRateB << "%" << endl;
        }
        if (tieB > 0) {
            cout << "    remisy: " << tieRateB << "%" << endl;
        }
        if (defB > 0) {
            cout << "    przegrane: " << defRateB << "%" << endl;
        }
        cout << endl;
    }
    winRateC = ((winC/numOfRoundsC)*100);
    defRateC = ((defC/numOfRoundsC)*100);
    tieRateC = ((tieC/numOfRoundsC)*100);
    if (numOfRoundsC > 0) {
        cout << "gracz c" << endl;
        if (winC > 0) {
            cout << "    wygrane: " << winRateC<< "%" << endl;
        }
        if (tieC > 0) {
            cout << "    remisy: " << tieRateC << "%" << endl;
        }
        if (defC > 0) {
            cout << "    przegrane: " << defRateC << "%" << endl;
        }
        cout << endl;
    }
    winRateD = ((winD/numOfRoundsD)*100);
    defRateD = ((defD/numOfRoundsD)*100);
    tieRateD = ((tieD/numOfRoundsD)*100);
    if (numOfRoundsD > 0) {
        cout << "gracz d" << endl;
        if (winD > 0) {
            cout << "    wygrane: " << winRateD << "%" << endl;
        }
        if (tieD > 0) {
            cout << "    remisy: " << tieRateD << "%" << endl;
        }
        if (defD > 0) {
            cout << "    przegrane: " << defRateD << "%" << endl;
        }
        cout << endl;
    }
    winRateE = ((winE/numOfRoundsE)*100);
    defRateE = ((defE/numOfRoundsE)*100);
    tieRateE = ((tieE/numOfRoundsE)*100);
    if (numOfRoundsE > 0) {
        cout << "gracz e" << endl;
        if (winE> 0) {
            cout << "    wygrane: " << winRateE << "%" << endl;
        }
        if (tieE > 0) {
            cout << "    remisy: " << tieRateE << "%" << endl;
        }
        if (defE > 0) {
            cout << "    przegrane: " << defRateE << "%" << endl;
        }
        cout << endl;
    }
    return 0;
}
