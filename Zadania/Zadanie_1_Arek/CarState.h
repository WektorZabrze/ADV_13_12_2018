#ifndef CarState_h
#define CarState_h

#include <variant>
#include <iostream>

/*
 * Do tego pliku można dopisywać swój kod - nie należy jednak usuwać już 
 * napisanego przeze mnie. Jeśli komuś jest tak wygodniej, to można kod
 * podzielić na wiecej plików.  
 */

class CarState
{

	struct DrivesForward {
		void printInfo() { std::cout << "Car is driving forward." << std::endl; }
	};

	/*
	 * Tu proszę dopisać dwa pozostałe stany na wzór tego powyżej. 
	 */

public:
	
	using State = /* UZUPEŁNIJ */;


	void startDrivingForward() {
		m_currentCarState = std::visit(StartsDrivingForwardEvent(), m_currentCarState);
	}

	/*
	 * Tu proszę dopisać pozostałe metody realizujące zmianę stanu na wzór
	 * metody powyżej. 
	 * Proszę również napisać metodę printCurrentState która korzysta z 
	 * poznanego na prezentacji mechanizmu polimorfizmu. 
	 */

private:

	State m_currentCarState;

	struct StartsDrivingForwardEvent {

		State operator() (const DrivesForward& currentState) {
			std::cout << "Car is already driving forward." << std::endl;
			return currentState;
		}

		State operator() (const DrivesBackwards& currentState) {
			std::cout << "Car is driving backwards - must stop before driving forward." << std::endl;
			return currentState;
		}

		State operator() (const NotMoving& currentState) {
			std::cout << "Car started driving forward." << std::endl;
			return DrivesForward();
		}
	};

	/*
	 * Proszę dopisać pozostałe dwa eventy zmieniające stan - mają
	 * działać na podobnej zasadzie jak ten powyżej. 
	 */

};


#endif // CarState_h