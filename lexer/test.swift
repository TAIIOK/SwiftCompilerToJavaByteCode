//  Test.swift
//  Created by Roman Efimov on 22.02.17.
//  Copyright © 2017 Roman Efimov. All rights reserved.
//

/*
 
 {"StickerPacks":[
 {
 "name": "test",
 "count": 1,
 "links": ["https://pp.vk.me/c606621/v606621505/7af7/dZnzJQLMFVs.jpg"]
 }
 ]
 }
 
 */

import Foundation

var varuble = 4
let constant = 3

var double = 3123.1231231

var hex = 0xFFF

var SD = "SD"
var __ = SD

__ == "s"

var trueBool:Bool = true
var falseBool:Bool = false

var int:Int = 0
var char:Character = "s"
var string:String = "string"
var doublevar:Double = 0.1
var float:Float = 0.1


var stringvar = "testing string"

if (trueBool || falseBool )
{
}

if (trueBool && falseBool )
{
}


if(varuble == constant){
    
    print("равны")
    
}
else if (varuble < constant){
}
else {
}

while varuble==constant{
}

repeat{
    
    print("")
    
}while (varuble>constant)

for index in 1...5 {
    print("\(index) times 5 is \(index * 5)")
}

func myFunc(dad:Int) -> Bool {
    return true
}

switch trueBool {
    
case true: break
    
case false: break
    
default: break
    
}

