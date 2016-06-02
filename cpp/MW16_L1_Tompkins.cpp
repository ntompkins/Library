/*
 Author: Nathan Tompkins
 Course: COSC 1337 Summer 2016 MW16 
 Instructor: Thayer
 Lab 1: Calculate restaurant bill and BMI calculator
*/

/*
Write one program that solves two problems about nutrition: calculate a restaurant bill and calculate your body mass index (BMI). The steps are:
1) Restaurant bill - write code that calculates a restaurant bill given cost of food and tip percentage:
            a) Ask for and get the cost of food. Use data type double.
            b) Ask for and get the tip percentage. Use data type double.
            c) Internally, declare the tax rate: const double tax_rate = 0.0825. Do not ask for tax rate.
            d) Compute the total bill: food cost * tax rate + tip.
                What should the tip be? Based on food cost? Food cost and tax? You decide; provide comments.
            e) Print out the total bill.
*/
#include <iostream>
main() {
	std::cout<<"a)mount of bill; b)mi? ";
	char response;
	cin>>response;
	response =  response.tolower();
	
	if (response=="a") {
		// Restaurant Bill
		std::cout<<"BILL CALCULATOR\n";
		// get the cost of the food
		double cost=0;
		std::cout<<"What was the cost of the food? $";
		std::cin>>cost;
	
		// get tip percentage
		double tipRate=0;
		std::cout<<"What is your tip percentage? ";
		std::cin>>tipRate;
		
		// set tipRate to percentage
		tipRate = tipRate / 100;
		
		// calculate subtotal
		double subtotal=0;
		subtotal = cost + (cost * tipRate);
		std::cout<<"Your subtotal is: $"<<subtotal;
		
		// calculate tax
		double tax_rate = 0.0825;
		
		// calculate total bill
		double total = subtotal + (tax_rate * subtotal);
		
		std::cout<<"\nYour total bill is $"<<total; // need to round to .00
} if (response == "b") {
		// BMI Calculator
		std::cout<<"\n\nBMI CALCULATOR\n";
		/*
		 Body Mass Index (BMI) – write code that computes BMI. The formula is:
	     BMI = (weight in pounds / (height in inches x height in inches) ) x 703
	            a) Ask for and get the required data. Use data type int.
	            b) Calculate the BMI. For the result, use data type double.
	            c) Print out the BMI.
		*/
		
		// get weight
		int pounds=0;
		std::cout<<"What is your weight (in lbs)? ";
		std::cin>>pounds;
		std::cout<<"Your weight is "<<pounds;
		
		// get height
		int height=0;
		std::cout<<"\nWhat is your height (in inches)? ";
		std::cin>>height;
		std::cout<<"Your height is "<<height;
		
		double bmi=0;
		bmi = (pounds / (height * height) * 703);
		std::cout<<bmi;
	}
}		
