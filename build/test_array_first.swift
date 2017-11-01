var new:[Int] = [1,2,3,4,5,6,7,9,11,25,-5,0]

var N = new.count()
var tmp = 0
var i:Int = 0
var j:Int = 0
for i in 0 ... N - 1{
    for j in 0 ... N - 1{

        if (new[j] > new[j + 1]){

            tmp = new[j];
            new[j] = new[j + 1];
            new[j + 1] = tmp;

        }

    }
}

i = 0

while(i < N){
    print(new[i])
    i = i + 1
}



