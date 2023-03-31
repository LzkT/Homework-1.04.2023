#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

    int main()
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        string name = "C:\\Users\\Елизавета\\source\\repos\\Алгоритм Прима\\example2.txt";
        ifstream f(name);

        int r;
        int max = 0, count = 0;

        while (f >> r)
        {
            count++;
            if ((count % 3 != 0) && (r - 1 > max))
            {
                max = r - 1;
            }
        };

        int** arr = new int* [max+1];
        for (int i = 0; i < max+1; i++)
        {          
            arr[i] = new int[i]; 
        }

        int* massiv = new int[count];

        f.close();

        ifstream file(name);

        int p, j = 0;

        while (file >> p)
        {
            massiv[j] = p;
            j++;
        };

        file.close();

        for (int i = 0; i < count - 2; i = i + 3)
        {
            arr[massiv[i] -1][massiv[i + 1] - 1] = massiv[i + 2];
        };

            int n = max +1;
            bool* visited = new bool[n];
            memset(visited, false, sizeof(bool) * n);
            visited[0] = true;
            for (int l = 0; l < n - 1; l++)
            {
                int minx = -1, miny = -1;
                for (int i = 0; i < n; i++)
                {
                    if (visited[i])
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (!visited[j] && arr[i][j] > 0 && (miny == -1 || arr[i][j] < arr[miny][minx]))
                            {
                                miny = i, minx = j;
                            };
                        };
                    };
                };
                visited[minx] = true;
                cout << miny + 1 << ' ' << minx + 1 << endl;
            };


           system("pause");

            for (int i = 0; i < max+1; i++) 
            {
                delete[] arr[i];  
            }

            delete[] massiv;
            delete[] visited;
    };

