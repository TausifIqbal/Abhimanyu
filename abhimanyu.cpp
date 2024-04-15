// Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies.
// Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back. 
//  
// Given:
//   Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11 powers
// Abhmanyu start from the innermost circle with p power Abhimanyu has a boon to skip fighting enemy
// a times 
//  Abhmanyu can recharge himself with power b times 
//  Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. 
//  If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle
//   k3 and k7 enemies are endured with power to regenerate themselves once with half of their initial
// power and can attack Abhimanyu from behind if he is battling in iteratively next circle 
//  
//  
// Write an algorithm to find if Abhimanyu can cross the Chakravyuh and test it with two sets of test cases.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define N 11 // number of circles

struct state{
    int circle;
    int current_power;
    int recharge;
    int skip;
};
int main(int argc,char** argv){
    const char* test_file = argv[1];
    freopen(test_file,"r",stdin);

    int skip,recharge,abhimanyu_power;
    vector<int> enemy_power(N);
    cin>>skip>>recharge>>abhimanyu_power;
    for(int i=0;i<11;i++){
        cin>>enemy_power[i];
    }

    // k3 can regenerate and attack from behind when abhimanyu is battling  k4, so  power required to pass 4th circle = k4 + k3/2
    enemy_power[3] += enemy_power[2]/2;
    // k7 can regenerate and attack from behind when abhimanyu is battling  k8, so power required to pass 8th circle = k8 + k7/2
    enemy_power[7] += enemy_power[6]/2;

    // check if abhimanyu can skip all enemies
    if(skip >= N){
        cout<<"YES\n";
        return 0;
    }
    // number of fight abhimanyu must need to skip is  ki> abhimanyu_power
    int required_skip = 0;
    for(int i=0;i<N;i++){
        if(enemy_power[i] > abhimanyu_power){
            required_skip++;
        }
    } 
    if(required_skip>skip){
        cout<<"NO\n";
        return 0;
    }

    // state (circle,current_power,recharge, skip)
    int abhimanyu_current_power = abhimanyu_power;
    queue<state> q;
    q.push({0,abhimanyu_power,recharge,skip});
    while(q.size()){
        state s = q.front();
        q.pop();  
        if(s.circle == N){
            cout<<"YES\n";
            return 0;
        }
        // if enemy is stronger than abhimanyu max power, then skip the fight
        if(abhimanyu_power < enemy_power[s.circle]){
            if(s.skip>=1){
                q.push({s.circle+1,s.current_power,s.recharge,s.skip-1});
            }
            continue;
        }
        // if abhimanyu can defeat the enemy without use of special power (recharge/skip) take the fight
        if(s.current_power >= enemy_power[s.circle]){
            q.push({s.circle+1,s.current_power - enemy_power[s.circle],s.recharge,s.skip});
        }else{
            // abhimanyu can't defeat the enemy without use special power (recharge/skip)
            if(s.recharge >= 1){
                q.push({s.circle+1,abhimanyu_power- enemy_power[s.circle],s.recharge-1,s.skip});
            }
            if(s.skip>=1){

                q.push({s.circle+1,s.current_power,s.recharge,s.skip-1});
            }
        }

    }
    cout<<"NO\n";
    return 0;
}