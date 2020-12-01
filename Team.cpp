#include <iostream>
 
int main()
{
        int cycle;
        int ans = 0;
 
        std::cin >> cycle;
 
        for(int i = 0; i < cycle; i++)
        {
                short a, b, c;
 
                std::cin >> a >> b >> c;
 
                if ((a + b + c) >= 2)
                {
                        ans++;
                }
        }       
 
        std::cout << ans << "\n";
 
        return 0;
}