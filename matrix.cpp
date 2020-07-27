#include <iostream>
using namespace std;

typedef int mnum;

int main() {

	mnum a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4; //Matrix

	cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4 >> c1 >> c2 >> c3 >> c4 >> d1 >> d2 >> d3 >> d4;

	mnum cq31, cq32, cq33; //Square cache
	mnum cd1, cd2, cd3; //Rectangle cache
	mnum ma1, mb1, mc1, md1; //Algebraic addons

	//Determinant claculating
	cq31 = a3 * b4 - a4 * b3; cq32 = b3 * c4 - c3 * b4; cq33 = c3 * d4 - d3 * c4;
	cd1 = a3 * c4 - c3 * a4; cd2 = a3 * d4 - d3 * a4; cd3 = b3 * d4 - b4 * d3;

	ma1 = b2 * cq33 - c2 * cd3 + d2 * cq32;
	mb1 = -a2 * cq33 + c2 * cd2 - d2 * cd1;
	mc1 = a2 * cd3 - b2 * cd2 + d2 * cq31;
	md1 = -a2 * cq32 + b2 * cd1 - c2 * cq31;

	mnum determinant = a1 * ma1 + b1 * mb1 + c1 * mc1 + d1 * md1;

	if (determinant) {
		cout << "Determinant: " << determinant << endl;
	} else {
		cout << "Haven't inverse matrix" << endl;
	}

	//Calculating inverse matrix
	mnum cq11 = a1 * b2 - b1 * a2, cq12 = b1 * c2 - c1 * b2, cq13 = c1 * d2 - d1 * c2;
	mnum cb1 = a1 * c2 - a2 * c1, cb2 = a1 * d2 - a2 * d1, cb3 = b1 * d2 - b2 * d1;
	mnum ma2, mb2, mc2, md2, ma3, mb3, mc3, md3, ma4, mb4, mc4, md4;

	ma2 = -b1 * cq33 + c1 * cd3 - d1 * cq32;
	mb2 = a1 * cq33 - c1 * cd2 + d1 * cd1;
	mc2 = -a1 * cd3 + b1 * cd2 - d1 * cq31;
	md2 = a1 * cq32 - b1 * cd1 + c1 * cq31;

	ma3 = b4 * cq13 - c4 * cb3 + d4 * cq12;
	mb3 = -a4 * cq13 + c4 * cb2 - d4 * cb1;
	mc3 = a4 * cb3 - b4 * cb2 + d4 * cq11;
	md3 = -a4 * cq12 + b4 * cb1 - c4 * cq11;

	ma4 = -b3 * cq13 + c3 * cb3 - d3 * cq12;
	mb4 = a3 * cq13 - c3 * cb2 + d3 * cb1;
	mc4 = -a3 * cb3 + b3 * cb2 - d3 * cq11;
	md4 = a3 * cq12 - b3 * cb1 + c3 * cq11;

	//Display
	cout << ma1 << "\t" << mb1 << "\t" << mc1 << "\t" << md1 << endl
		<< ma2 << "\t" << mb2 << "\t" << mc2 << "\t" << md2 << endl
		<< ma3 << "\t" << mb3 << "\t" << mc3 << "\t" << md3 << endl
		<< ma4 << "\t" << mb4 << "\t" << mc4 << "\t" << md4 << endl;

	return 0;
}