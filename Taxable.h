#ifndef _SICT_TAXABLE_H
#define _SICT_TAXABLE_H

namespace sict
{
	class Taxable
	{
		float tax_rate;

	public:
		Taxable(float TaxRate) : tax_rate{ TaxRate } {}

		float operator()(float prc) const {
			return (1 + tax_rate) * prc;
		}
	};
}

#endif