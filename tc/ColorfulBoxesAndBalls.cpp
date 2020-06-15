class ColorfulBoxesAndBalls {
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
		int sum = numRed*onlyRed + numBlue*onlyBlue;
		if (2 * bothColors - onlyRed - onlyBlue <= 0) return sum;
		int k = numRed<numBlue ? numRed : numBlue;
		for (int i = 0; i<k; i++)
			sum += (2 * bothColors - onlyRed - onlyBlue);
		return sum;
	}
};