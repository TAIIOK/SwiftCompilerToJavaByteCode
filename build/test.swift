func fact(kek:Int) -> Int {

    if(kek > 1){
        return kek * fact(kek:kek - 1)
    }
    else if ( kek > 2){
        print("TESTING")
        return 0
    }
    else {
        return 1
    }

    return 5

}


func fact1(kek:Int,ksk:Int) -> Int {


    if(kek < 0){
        return 0
    }

    if(kek == 1){
        return 1
    }

    var new:[Int] = [1,2,3]

    return kek * fact1(kek:kek - 1,ksk:ksk)

}

var d = toInt(readLine())

var s = 1

print(d)

s = fact(kek:d)

//var dsd:[Int] = [1,2,3,4]

//s = fact1(kek:d,ksk:d)

print(s)
