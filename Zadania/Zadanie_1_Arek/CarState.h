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

	struct DrivesBackwards{
		void printInfo() { std::cout << "Car is driving backwards." << std::endl; }
	};

	struct NotMoving {
		void printInfo() { std::cout << "Car is not moving." << std::endl; }
	};

public:
	
	using State = std::variant<NotMoving, DrivesBackwards, DrivesForward>;


	void startDrivingForward() {
		m_currentCarState = std::visit(StartsDrivingForwardEvent(), m_currentCarState);
	}

	void startDrivingBackwards() {
		m_currentCarState = std::visit(StartsDrivingBackwardEvent(), m_currentCarState);
	}

	void stopDriving() {
		m_currentCarState = std::visit(StopsDrivingEvent(), m_currentCarState);
	}

	void printCurrentState() {
		auto fun = [](auto& state){ state.printInfo();};
		std::visit(fun, m_currentCarState);
	}

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
			(void)currentState;
			std::cout << "Car started driving forward." << std::endl;
			return DrivesForward();
		}
	};

	struct StartsDrivingBackwardEvent {

		State operator() (const DrivesForward& currentState) {
			std::cout << "Car is driving forwards - must stop before driving backward." << std::endl;
			return currentState;
		}

		State operator() (const DrivesBackwards& currentState) {
			std::cout << "Car is already driving backward." << std::endl;
			return currentState;
		}

		State operator() (const NotMoving& currentState) {
			(void)currentState;
			std::cout << "Car started driving backward." << std::endl;
			return DrivesBackwards();
		}
	};

	struct StopsDrivingEvent {

		State operator() (const DrivesForward& currentState) {
			(void)currentState;
			std::cout << "Car stoped driving forward. Now it is not moving." << std::endl;
			return NotMoving();
		}

		State operator() (const DrivesBackwards& currentState) {
			(void)currentState;
			std::cout << "Car stoped driving backwards. Now it is not moving. " << std::endl;
			return NotMoving();
		}

		State operator() (const NotMoving& currentState) {
			std::cout << "Car has already stoped." << std::endl;
			return currentState;
		}
	};

};


#endif // CarState_h