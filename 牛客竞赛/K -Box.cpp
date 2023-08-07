#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int maxscore = 0;
int calscore(std::vector<int>& boxes, std::vector<int>& balls)
{
    int ans=0;
    for (int i = 0;i < boxes.size();i++)
    {
        ans += boxes[i] * balls[i];
    }
    return ans;
}

void backtrack1(std::vector<int>& boxes, std::vector<int>& balls,int pos)
{
    int n = boxes.size()-1;
    if (pos > n - 1)
        return;
        if (balls[pos] == 1&&pos<n)
        {
            
            if (pos>0&&balls[pos - 1] == 0 )
            {
                balls[pos - 1] = 1;
                balls[pos] = 0;
                maxscore = max(maxscore, calscore(boxes, balls));
                backtrack1(boxes, balls, pos + 1);
                balls[pos - 1] = 0;
                balls[pos] = 1;
            }
            if (pos < n - 1&&balls[pos + 1] == 0  )
            {
                balls[pos + 1] = 1;
                balls[pos] = 0;
                maxscore = max(maxscore, calscore(boxes, balls));
                backtrack1(boxes, balls, pos + 1);
                balls[pos + 1] = 0;
                balls[pos] = 1;
            }
            backtrack1(boxes, balls, pos + 1);
        } 
        backtrack1(boxes, balls, pos + 1);    
    
}
void backtrack2(std::vector<int>& boxes, std::vector<int>& balls, int pos)
{
    int n = boxes.size() - 1;
    if (pos<0)
        return;
    if (balls[pos] == 1 && pos>=0)
    {

        if (pos > 0 && balls[pos - 1] == 0)
        {
            balls[pos - 1] = 1;
            balls[pos] = 0;
            maxscore = max(maxscore, calscore(boxes, balls));
            backtrack2(boxes, balls, pos - 1);
            balls[pos - 1] = 0;
            balls[pos] = 1;
        }
        else if (pos < n - 1 && balls[pos + 1] == 0)
        {
            balls[pos + 1] = 1;
            balls[pos] = 0;
            maxscore = max(maxscore, calscore(boxes, balls));
            backtrack2(boxes, balls, pos - 1);
            balls[pos + 1] = 0;
            balls[pos] = 1;
        }
    }
    backtrack2(boxes, balls, pos - 1);

}



int main() {
    int n;
    std::cin >> n;
    std::vector<int> boxes(n+1);
    std::vector<int> balls(n+1);
    for (int i = 0; i < n; i++) {
        std::cin >> boxes[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> balls[i];
    }
    maxscore = calscore(boxes, balls);
    backtrack1(boxes, balls, 0);
    backtrack2(boxes, balls, n-1);
    cout << maxscore<<endl;

    return 0;
}
