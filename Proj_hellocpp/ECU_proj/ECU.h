

class ECU
{
public:
	ECU();
	~ECU();
	void handleCommand(char cCommand);


private:
	bool m_bActivatedHydraulicJacks; // Button A
	bool m_bActivatedBeltTires; // Button B
	bool m_bActivatedIRillumination; // Button E

	int numHydraulicCalls = 0;
	int numBeltCalls = 0;
	int numIRCalls = 0;

	void actuateHydraulicJacks();
	void actuateBeltTires();
	void actuateIRillumination();

};
