
//var a:[String] = ["2","2","s"]

//a[2] = "s"

var a:[Int] = [1,2,3]

a[2] = 4

var n = a.count()

var s = "String"

var b = 1 - (1 + 2)


var j = 0
var tmp = 0

while (i >= 0){
    while(j < i){
        if (a[j] > a[j + 1]){
            tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
        }
        j = j + 1
    }
    i = i - 1
}

var i = 0



func vv(s:Int,d:Int) -> Int{

    return 2
}



i  = vv(s:i,d:2)


/*
for (int i = n - 1; i >= 0; i--)
{
    for (int j = 0; j < i; j++)
    {
        if (a[j] > a[j + 1])
        {
            int tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
        }
    }
}
*/
