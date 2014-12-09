


class CAccount
{
private:
	float mBalance;
public:
	void Deposit(float amount);
	void ChangeBalance(float amount);
	float GetBalance();
	virtual void Withdrawal(float amount);
	virtual void Interest();

};

void CAccount::Deposit(float amount)
{
	mBalance += amount;
}

void CAccount::ChangeBalance(float amount)
{
	mBalance = amount;
}

float CAccount::GetBalance()
{
	return mBalance;
}

