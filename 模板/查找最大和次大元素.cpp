/*
对于给定的含有n元素的无序序列，求这个序列中最大和次大的两个不同的元素。
例如：（2, 5, 1, 4, 6, 3），最大元素为6，次大元素为5
*/

/*
求解：
对于无序序列a[low.high]中，采用分治法求最大元素max1和次大元素max2的过程如下：
   （1）a[low.high]中只有一个元素：则max1=a[low]，max2=-INF（-∞）（要求它们是不同的元素）。
   （2）a[low.high]中只有两个元素：则max1=MAX{a[low]，a[high]}，max2=MIN{a[low]，a[high]}。
   （3）a[low.high]中有两个以上元素：按中间位置mid=(low+high)/2划分为a[low..mid]和a[mid+1..high]左右两个区间（注意左区间包含a[mid]元素）。
   求出左区间最大元素lmax1和次大元素lmax2，求出右区间最大元素rmax1和次大元素rmax2。
   合并：若lmax1>rmax1，则max1=lmax1，max2=MAX{lmax2，rmax1}；否则max1=rmax1，max2=MAX{lmax1，rmax2}。
*/

#define INF 1e10
#include<algorithm>

void solve(int a[], int low, int high, int &max1, int &max2)
{   
    if (low == high)		//区间只有一个元素
    {
        max1 = a[low];
        max2 = -INF;
    }
    else if (low == high - 1)	//区间只有两个元素
    {	
        max1 = max(a[low], a[high]);
        max2 = min(a[low], a[high]);
    }
    else			//区间有两个以上元素
    {	
        int mid = (low + high) / 2;
        int lmax1, lmax2;
        solve(a, low, mid, lmax1, lmax2);	     //左区间求lmax1和lmax2
        int rmax1, rmax2;
        solve(a, mid+1, high, rmax1, rmax2);  //右区间求lmax1和lmax2
        
        if (lmax1 > rmax1)
        {   
            max1 = lmax1;
            max2 = max(lmax2, rmax1);	//lmax2,rmax1中求次大元素
        }
        else
        {
            max1 = rmax1;
            max2 = max(lmax1, rmax2); 
        }	                            //lmax1,rmax2中求次大元素	
    }
}
