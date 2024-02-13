#include <iostream>
using namespace std;

bool battleVictory = false;
int palo[] = { 1,2,3,4 };
int counter = 0;
double bet;
double money = 100;
string figure[] = { "","" };
string asVal;
int value[] = { 0, 0 };
int myHand[] = { 0, 0 };
int cardID[] = { 0, 0 };
int history[48];
int fix = 0;
bool playerPlant = false;
bool crupPlant = false;
bool flipTable1 = false;
string answer;
int storyId;
int manipulation;
string name;

void lore() {

	cout << "Introduce tu nombre: ";
	cin >> name;
	storyId = rand() % 3;

	// Nombres easter egg

	name[0] = toupper(name[0]);

	if (name._Equal("Arnaly") || name._Equal("Arnau"))
	{
		storyId = 20;
	}

	else if (name._Equal("Mickey")) {
		storyId = 30;
	}

	cout << name + ", ";
	switch (storyId) {
	case 0:
		cout << "has vivido toda tu vida a merced del destino y la casualidad. Pasaste la ESO a medias, fuiste a bachillerato y llegaste a la universidad"
			<< " para hacer una carrera que no te motivaba ni gustaba lo mas minimo. Un dia, conociste a un extrano en el metro, un vagabundo de los habituales en la L1,"
			<< " que se puso a cantar para conseguir limosna. Por algun motivo, su cancion hablaba de atreverse a hacer las cosas, y eso te conmovio.\n\n"
			<< "Hoy, el dia despues de ese encuentro, te has decidido a no ir a tus clases, y coger los pocos ahorros que tienes para ir al casino.\n"
			<< "Una vez llegas al casino, vas directo a la mesa de Blackjack, el unico juego de apuestas que conoces y al que sabes jugar. Te sientas en la mesa, "
			<< "con tu corazon latiendo en tu garganta, y te preparas para apostar.\n\n";

		cout << name << ", tienes la percepcion de la realidad alterada. Un empate sera una victoria para ti.\n";


		break;
	case 1:
		cout << "eres un artista en apuros, que ha llegado al casino con sus ultimos ahorros. Con la esperanza de que un milagro te salve del desalojo, "
			<< "te lanzas a las mesas the Blackjack. Las cartas parecen bailar a su ritmo, trayendo victorias fugaces y suenos de redencion. Finalmente, decides que es tu"
			<< " turno para apostar, y con el corazon en la mano y las cartas en el pecho, te preparas para el juego.\n";
		cout << name << ", la voz es tu aliada. Si pierdes, tienes un 50% de posibilidad de persuadir al crupier y recuperar parte de la apuesta\n";
		break;
	case 2:
		cout << "tras hacer unas malas decisiones empresariales, has perdido tu trabajo, y a causa de la mala situacion economica que eso ha conllevado, tu esposa e hijos te han abandonado. "
			<< "Has intentado durante unos meses recuperarte economicamente, pero no has podido hacer nada. El gobierno te ha retirado la ayuda economica y apenas te queda dinero. Solo "
			<< "ves una unica posibilidad de recomponerte. Con dudas y muy poco dinero, entras al casino y te sientas en la mesa de Blackjack. El juego va a empezar. No te queda opcion.\n";

		cout << name << ", te da igual todo. Si haces un all-in y fracasas,  solo perderas un 70%.\n";
		break;
	case 20:
		cout << "poco antes de acabar la ESO, descubriste un sitio de apuestas en linea. Alli empezaste a jugar con el dinero y poco despues se convirtio en tu diario. Algo necesario."
			<< " Despues de acabar tus estudios en informatica, decidiste tomar un descanso de ellos, y centrarte en vivir, lo cual significo muchas mas apuestas.\n"
			<< "Un mes despues, te encuentras solo y con poco dinero. Tus padres te han echado de casa despues de destrozar tu ordenador, y solo te quedan unos pocos ahorros en forma de Litecoin."
			<< "Conseguiste sacar esos ahorros, y con lo poco que te queda, solo se te ocurre la unica cosa que sabes hacer: apostarlo todo. Asi pues, decides ir al casino, y multiplicar"
			<< " tu dinero.	Empieza el juego.\n";

		cout << name << ", tienes una capacidad innata de duplicar tu dinero. Tus victorias te daran el triple de dinero.\n";
		break;
	case 30:
		cout << "eres el hijo de un rico empresario espanol que controla los bancos y forma parte de la elite de Tartaria. Hace dos dias, le preguntaste si podias unirte a el, "
			<< "a lo que te respondio que no, porque tu naciste manana. Lleno de frustracion, le dijiste que el ya sabia del ultimo reset, y el te castigo.\n"
			<< "Esa misma tarde, te escapaste de casa con unos miseros ahorros que tienes en tu habitacion, y fuiste al casino que el regenta, para demostrar que eres digno de ser "
			<< "su hijo y parte de la elite como Jim Carrey.\nEntras al casino, pero no ves a tu padre. Igualmente, decides ir a la mesa de Blackjack, el unico juego que te enseno a jugar."
			<< " Te preparas en la silla, y empieza el juego.\n";
		cout << name << ", tienes el poder de la manipulacion. Si te quedas sin dinero, puedes recuperar una cantidad aleatoria entre 1 y 100.";
		break;
	}
}


void playerBet() {

	cout << "Se va a revelar la primera carta. Cual es tu apuesta? (Te quedan " << money << "$)\n";

	do
	{

		cin >> bet;

		if (money < bet)
		{
			cout << "No tienes tanto dinero. Introduce una apuesta valida.\n";
		}

		else if (bet == money)
		{
			cout << "Se te ha ido la cabeza y decides apostar todo tu dinero. Tu familia estaria contenta.\n";
		}

	} while (bet > money);

	money -= bet;
}



void chooseFigure() {
	if (playerPlant == false && crupPlant == false)
	{

		for (int i = 0; i < 2; i++)
		{


			int choose = rand() % 4;
			palo[choose];

			switch (palo[choose]) {
			case 1:
				figure[i] = " de corazones";
				break;
			case 2:
				figure[i] = " de picas";
				cardID[i] += 13;
				break;
			case 3:
				figure[i] = " de treboles";
				cardID[i] += 26;
				break;
			case 4:
				figure[i] = " de diamantes";
				cardID[i] += 39;
				break;
			}

			if (i == 0)
			{
				cout << figure[i] << "\n";
			}


		}

	}

	else if (playerPlant == true && crupPlant == false) {
		int choose = rand() % 4;
		palo[choose];

		switch (palo[choose]) {
		case 1:
			figure[1] = " de corazones";
			break;
		case 2:
			figure[1] = " de picas";
			cardID[1] += 13;
			break;
		case 3:
			figure[1] = " de treboles";
			cardID[1] += 26;
			break;
		case 4:
			figure[1] = " de diamantes";
			cardID[1] += 39;
			break;
		}

		cout << figure[1] + "\n";
	}

	else if (playerPlant == false && crupPlant == true)
	{
		int choose = rand() % 4;
		palo[choose];

		switch (palo[choose]) {
		case 1:
			figure[0] = " de corazones";
			break;
		case 2:
			figure[0] = " de picas";
			cardID[0] += 13;
			break;
		case 3:
			figure[0] = " de treboles";
			cardID[0] += 26;
			break;
		case 4:
			figure[0] = " de diamantes";
			cardID[0] += 39;
			break;
		}

		cout << figure[0] << "\n";

	}

}

void chooseNumber() {

	if (playerPlant == false && crupPlant == false)
	{


		for (int i = 0; i < 2; i++)
		{

			int choose = rand() % 13 + 1;

			if (choose >= 2 && choose <= 10)
			{
				value[i] = choose;
				cardID[i] = value[i];

				if (i == 0)
				{
					cout << value[i];
				}
			}

			else if (choose == 1)
			{
				if (i == 0)
				{
					cout << "As";
				}

				value[i] = 1;
				cardID[i] = value[i];
			}

			else
			{
				value[i] = 10;
				cardID[i] = value[i];

				switch (choose) {
				case 11:

					if (i == 0)
					{
						cout << "Sota";
					}

					cardID[i] += 1;
					break;

				case 12:
					if (i == 0)
					{
						cout << "Reina";
					}

					cardID[i] += 2;
					break;

				case 13:
					if (i == 0)
					{
						cout << "Rey";
					}

					cardID[i] += 3;

					break;
				}




			}

			fix++;

		}

	}

	else if (playerPlant == true && crupPlant == false)
	{
		int choose = rand() % 13 + 1;


		if (choose >= 2 && choose <= 10)
		{
			value[1] = choose;
			cardID[1] = value[1];
			cout << "El crupier ha sacado un ";
			cout << value[1];

		}

		else if (choose == 1)
		{


			value[1] = 1;
			cardID[1] = value[1];
			cout << "El crupier ha sacado un ";
			cout << "As";
		}

		else
		{
			value[1] = 10;
			cardID[1] = value[1];

			switch (choose) {
			case 11:

				cardID[1] += 1;
				cout << "El crupier ha sacado una ";
				cout << "Sota";
				break;

			case 12:


				cardID[1] += 2;
				cout << "El crupier ha sacado una ";
				cout << "Reina";
				break;

			case 13:

				cardID[1] += 3;
				cout << "El crupier ha sacado un ";
				cout << "Rey";
				break;
			}
		}
	}

	else if (playerPlant == false && crupPlant == true)
	{
		int choose = rand() % 13 + 1;

		if (choose >= 2 && choose <= 10)
		{
			value[0] = choose;
			cardID[0] = value[0];

			cout << value[0];

		}

		else if (choose == 1)
		{
			cout << "As";


			value[0] = 1;
			cardID[0] = value[0];
		}

		else
		{
			value[0] = 10;
			cardID[0] = value[0];

			switch (choose) {
			case 11:

				cout << "Sota";


				cardID[0] += 1;
				break;

			case 12:

				cout << "Reina";


				cardID[0] += 2;
				break;

			case 13:

				cout << "Rey";


				cardID[0] += 3;

				break;
			}

		}

		fix++;
	}
}

void aceCheck() {

	if (playerPlant == false && crupPlant == false)
	{


		asVal = "1";

		for (int i = 0; i < 2; i++)
		{

			do
			{


				if (cardID[i] == 1 || cardID[i] == 14 || cardID[i] == 27 || cardID[i] == 40)
				{
					if (myHand[i] + 11 > 21)
					{
						if (i == 0)
						{
							cout << "El as tendra un valor de 1 debido a que perderias en caso contrario.\n";
						}

						value[i] = 1;
					}

					else
					{

						if (i == 1)
						{
							value[i] = 11;
						}

						else {
							cout << "Que valor quieres que tenga el as ? (escribe 1 o 2)\n";
							cout << "1 - 1\n";
							cout << "2 - 11\n";


							cin >> asVal;

							if (asVal == "1")
							{
								value[i] = 1;
							}
							else if (asVal == "2")
							{
								value[i] = 11;
							}

						}

					}
				}


			} while (!asVal._Equal("1") && !asVal._Equal("2"));

			history[counter] = cardID[i];
			myHand[i] += value[i];
		}
	}

	else if (playerPlant == true && crupPlant == false)
	{
		if (myHand[1] + 11 > 21 && value[1] == 1)
		{
			value[1] = 1;
			myHand[1] += value[1];
		}

		else if (value[1] == 1 && myHand[1] + 11 <= 21)
		{
			value[1] = 11;
			myHand[1] += value[1];
		}

		else
		{
			myHand[1] += value[1];
		}

		history[counter] = cardID[1];
	}

	else if (playerPlant == false && crupPlant == true)
	{

		do
		{
			if (cardID[0] == 1 || cardID[0] == 14 || cardID[0] == 27 || cardID[0] == 40)
			{
				if (myHand[0] + 11 > 21)
				{

					cout << "El as tendra un valor de 1 debido a que perderias en caso contrario.\n";

					value[0] = 1;
				}

				else
				{

					cout << "Que valor quieres que tenga el as ? (escribe 1 o 2)\n";
					cout << "1 - 1\n";
					cout << "2 - 11\n";


					cin >> asVal;

					if (asVal == "1")
					{
						value[0] = 1;
					}
					else if (asVal == "2")
					{
						value[0] = 11;
					}



				}
			}


		} while (!asVal._Equal("1") && !asVal._Equal("2"));

		history[counter] = cardID[0];
		myHand[0] += value[0];
	}
}

void pickCard() {

label:

	chooseNumber();

	if (myHand[1] > 0 && fix == 2)
	{
		value[1] = 0;
		counter--;
	}

	chooseFigure();
	aceCheck();


	if (crupPlant != true) {
		for (int k = 0; k < (sizeof(history) / sizeof(int)); k++)
		{
			for (int i = 0; i < 2; i++)
			{



				if (counter != k && history[k] == cardID[i])
				{
					myHand[i] -= value[i];
					goto label;
				}

			}

		}
	}
	counter++;
}



void startingCards() {
	for (int i = 1; i < 3; i++)
	{



	label:



		chooseNumber();
		chooseFigure();
		aceCheck();

		if (i == 1)
		{
			myHand[1] = 0;

		}

		for (int k = 0; k < (sizeof(history) / sizeof(int)); k++)
		{
			for (int i = 0; i < 2; i++)
			{



				if (counter != k && history[k] == cardID[i])
				{
					myHand[i] -= value[i];
					counter--;
					goto label;
				}

			}

		}

		counter++;

	}
}


void checkCards() {


	if (myHand[0] == 21)
	{
		cout << "Tienes Blackjack. El crupier debe empatarte para ganar.\n";
		playerPlant = true;

		while (myHand[1] < myHand[0]) {
			pickCard();
		}
	}

	else
	{

		do
		{


			cout << "Tienes " << myHand[0] << ", el crupier tiene " << myHand[1] << ". Quieres pedir otra carta?\n";
			cout << "1 - Si\n";
			cout << "2 - No\n";

			cin >> answer;

			if (answer._Equal("1"))
			{


				if (myHand[1] >= 17 && myHand[0] < myHand[1])
				{
					crupPlant = true;
					cout << "El crupier se ha plantado con " << myHand[1] << " por lo que tienes que superar su puntuacion.\n";

				}

				pickCard();
			}

			else {

				playerPlant = true;

				if (myHand[0] > myHand[1])
				{
					cout << "Te plantas con " << myHand[0] << ". El crupier tiene " << myHand[1] << ", asi que tiene que intentar superarte.\n";

				}

				while (myHand[1] < myHand[0]) {
					pickCard();
				}


			}


		} while (myHand[0] < 21 && answer._Equal("1"));



	}

}


void flipTable() {

	if ((myHand[0] > 21 || (myHand[0] < myHand[1] && myHand[1] < 22)) || (myHand[0] == myHand[1] && playerPlant))
	{
		if ((myHand[0] > 21 || (myHand[0] < myHand[1] && myHand[1] < 22)))
		{
			cout << "Tienes " << myHand[0] << ", el crupier tiene " << myHand[1] << ". Has perdido.\n";

			if (money == 0 && storyId == 30)
			{
				money = rand() % 100 + 1;
				cout << "Te has quedado sin dinero, pero gracias a tu habilidad has recuperado " << money << "creditos.\nQue vas a hacer?\n";
			}

			else if (storyId == 1)
			{
				manipulation = rand() % 2 + 1;

				if (manipulation == 1)
				{
					cout << "Intentas convencer al crupier para que te devuelva parte del dinero pero fracasas en el intento.\nQue vas a hacer?\n";
				}

				else {
					bet = bet * (rand() % 10 + 1) / 10;
					cout << "Has manipulado al crupier con exito y has recuperado " << bet << " creditos.\nQue vas a hacer?\n";
					money += bet;
				}
			}

			else if (storyId == 2 && money == 0)
			{
				money = bet * 0.3;
				cout << "Al haber hecho un all-in, recuperas un 30% de tu apuesta gracias a tu habilidad.\nQue vas a hacer?\n";
			}
		}

		else
		{
			if (storyId == 0) {
				cout << "Tienes " << myHand[0] << ", el crupier tiene " << myHand[1] << ". Empate. Crees que has ganado, asi que le robas parte del dinero al crupier, que te mira con desprecio.\nQue vas a hacer?\n";
				money += bet * 2;
			}

			else {
				cout << "Tienes " << myHand[0] << ", el crupier tiene " << myHand[1] << ". Empate. Recuperas tu apuesta. Que vas a hacer?\n";
				money += bet;
			}
		}

		cout << "1 - Jugar otra vez\n";
		cout << "2 - Marcharse\n";
		cout << "3 - Tirar la mesa\n";
		cin >> answer;

		if (answer._Equal("2")) {
			system("cls");

		}
		else if (answer._Equal("3")) {
			system("cls");
			cout << "En un arrebato de ira decides tirar la mesa.\n";

			system("pause");
			flipTable1 = true;
		}

	}

	else if ((myHand[0] > myHand[1] && myHand[0] < 22) || (myHand[1] > 21 && myHand[0] < 22))
	{

		if (storyId == 20)
		{
			money += bet * 3;
			cout << "Has ganado la partida y has triplicado tu apuesta! Tienes " << money << "$. Quieres jugar otra vez?\n";
		}

		else {
			money += bet * 2;
			cout << "Has ganado la partida y duplicado tu apuesta! Tienes " << money << "$. Quieres jugar otra vez?\n";
		}

		cout << "1 - Si\n";
		cout << "2 - No\n";
		cout << "3 - Tirar la mesa\n";

		cin >> answer;

		if (answer._Equal("3")) {
			system("cls");
			cout << "En un arrebato de emocion y felicidad decides tirar la mesa.\n";

			system("pause");

			flipTable1 = true;
		}
	}

}

void restart() {
	myHand[0] = 0;
	myHand[1] = 0;
	crupPlant = false;
	playerPlant = false;

	for (int i = 0; i < sizeof(history) / sizeof(int); i++)
	{
		history[i] = 0;
	}

	for (int i = 0; i < sizeof(cardID) / sizeof(int); i++)
	{
		cardID[i] = 0;
	}

}

void bossFight() {

	int characterHPValue = 100;
	int securityHPValue = 200;
	int characterAttackValue = 20;
	int securityAttackValue = 30;

	cout << "Comienza el combate por el destino de tu vida, " << name << "!";

	while (characterHPValue > 0 && securityHPValue > 0 && battleVictory == false) {
		cout << "Que quieres hacer? (tienes puntos " << characterHPValue << " de vida)\n";
		cout << "1 - Atacar\n";
		cout << "2 - Curarte\n";
		cout << "3 - Persuadir\n";
		cin >> answer;

		if (answer._Equal("1"))
		{
			securityHPValue -= characterAttackValue;

			if (securityHPValue < 0) securityHPValue = 0;

			if (securityHPValue == 0) battleVictory = true;

			cout << "Has atacado al personal de seguridad y les has quitado " << characterAttackValue << " puntos de vida! Les quedan " << securityHPValue << ".\n";
		}
		else if (answer._Equal("2"))
		{
			characterHPValue += 40;

			if (characterHPValue > 100) characterHPValue = 100;

			cout << "Te has curado con exito 40 puntos de vida! Ahora tienes " << characterHPValue << ".\n";

		}
		else if (answer._Equal("3"))
		{
			if (storyId == 1)
			{
				cout << "Gracias a tus habilidades, logras persuadir al personal de seguridad y te dejan en paz.\n";
				battleVictory = true;
			}

			else cout << "El personal de seguridad se rie de ti y te hacen instakill. Has muerto.\n";
			characterHPValue = 0;
		}

		if (battleVictory == false)
		{
			characterHPValue -= securityAttackValue;
			if (characterHPValue < 0) characterHPValue = 0;

			cout << "El personal de seguridad te ha quitado 30 puntos de vida. Te quedan " << characterHPValue << ".\n";
		}



	}

	if (battleVictory) {
		cout << "Has ganado el combate!\n";
	}

	else cout << "Has muerto.\n";

}

void finalBattle() {

	cout << "La gran batalla final ha comenzado. " << name << " Vs la puerta de la caja fuerte! Estas preparado?\n";
	cout << "1 - Atacar\n";
	cout << "2 - Curarte\n";
	cout << "3 - Persuadir\n";
	cin >> answer;

	if (answer._Equal("1"))
	{
		cout << "Decides golpear una puerta de acero de mas de 50 centimetros de grosor. Te has destruido las manos y mueres desangrado. Final nefasto.\n";
	}

	else if (answer._Equal("2"))
	{
		cout << "Decides curarte sin que siquiera la puerta pueda golpearte (como va a hacerlo?, es una puerta, inutil.). Final nefasto.\n";
	}

	else if (answer._Equal("2"))
	{
		cout << "Decides persuadir una puerta. Si, una puerta. Te ha ignorado completamente. Final nefasto.\n";
	}

	else if (answer._Equal("win"))
	{
		cout << "Decides aprovecharte de los trucos del creador del juego para abrir la puerta de la boveda. Has logrado recuperar lo que te pertenece. Final bueno.\n";
	}

}

void boveda(bool open) {
	system("wait");
	system("cls");

	cout << "Avanzas hacia la sala donde crees que estara la caja fuerte. Encuentras una boveda. Ahi debe estar tu dinero.\nQue haces?\n1 - Pegarte con la puerta\n2 - Usar un taladro\n"
		<< "3 - Colocar dinamita\n4 - Rezar\n5 - Intentar abrirla normalmente\n6 - Teletransportarte adentro\n7 - Usar un sable laser\n8 - Comerte una judia";

	cin >> answer;

	if (answer._Equal("1")) {
		finalBattle();
	}
	else if (answer._Equal("2")) {
		cout << "Coges un taladro de tu mochila y empiezas a taladrar la puerta.... Pero... tu taladro es uno de bricolaje... eso no va a taladrar nada. Esperas horas con la esperanza de "
			<< "que atraviese la puerta... dias... semanas...\n\nFinal de bricolaje.";
	}
	else if (answer._Equal("3")) {
		cout << "Colocas dinamita en la puerta, la enciendes y buscas donde cubrirte. No hay lugar para cubrirse de la explosion. De repente te caes al suelo y te pitan los oidos.\n\nFinal explosivo.";
	}
	else if (answer._Equal("4")) {
		cout << "Empiezas a rezar plegarias para que se abra la puerta. Como no sabes latin, sin querer invocas a un demonio. Tu cuerpo empieza a arder en cuanto te ve.\n\nFinal ardiente.";
	}
	else if (answer._Equal("5") && open) {
		cout << "Intentas abrir la boveda como una persona normal, y se abre. Has desactivado la seguridad del casino, claro que se abre. Entras y encuentras todo tu dinero y el de todos los clientes.\n"
			<< "Has conseguido el objetivo.\n\nFinal bueno.";
	}
	else if (answer._Equal("5") && !open) {
		// AQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
		cout << "Intentas abrir la puerta, pero no se mueve ni un centimetro. Intentas hacer fuerza, pero en el acto te dislocas el hombro.\n\nbFinal pechofrio.";
	}
	else if (answer._Equal("6")) {
		cout << "Usas un mando teletransportador para entrar a la boveda.\n";
		int tpEnding = rand() % 3 + 1;
		switch (tpEnding) {
		case 1:
			cout << "Te teletransportas dentro de la boveda, pero literalmente. Eres parte de la pared, viendo el dinero tan cerca, pero sin posibilidad de desengancharte a nivel atomico de la pared."
				<< "\n\nFinal cuantico.";
			break;
		case 2:
			cout << "Te teletransportas dentro de la boveda, y consigues tu dinero y el de todos los clientes. Solo hay un pequeño problema. No puedes salir, ya que el mando se ha quedado fuera.\n\n"
				<< "Final atrapado.";
			break;
		case 3:
			cout << "Te teletransportas dentro de la boveda, y literalmente tu dinero vuelve a formar parte de ti. Todos los billetes, monedas y oro estan fusionados con tu cuerpo. Notas dolor y ardor"
				<< " por todo tu cuerpo, y te empiezas a asfixiar.\n\nFinal Midas.";
			break;
		}
	}
	else if (answer._Equal("7")) {
		cout << "Sacas el sable laser de Darth Maul de tu mochila. Lo enciendes apuntando hacia la puerta. El sable atraviesa la puerta a la perfeccion, al igual que tus tripas. El sable tiene dos "
			<< "filos.\n\nFinal cauterizante.";
	}
	else if (answer._Equal("8")) {
		cout << "Sacas una lata de judias que compraste a un vagabundo. Empiezas a comertelas, y tu pelo empieza a volverse dorado. Notas la fuerza de un guerrero cosmico por tus venas.\n"
			<< "De un golpe, tiras la puerta abajo, y te haces con el dinero de todo el casino. Lo agarras todo, y vuelas a traves del techo, dominando asi el Ultra Instinto."
			<< "\n\nFinal Super Saiyan.";
	}
	else {
		cout << "No te decides y acabas muriendo de tanto pensar.\n\nFinal indeciso.";
	}
}

void heist() {

	// A PARTIR DE AQUI VA A SER CODIGO SPAGHETTI POR EL BIEN DEL PROGRAMA Y NO DEL LECTOR. 

	// LORE DEL MAGNIFICO ROBO DEL CASINO PARA RECUPERAR TU DINERO. (TE HAN ROBADO CLARAMENTE Y NO MERECES ESTE DESTINO)

	// JUEGO TIPO HENRY STICKMIN (buscalo si no lo conoces, juego 10/10 gratis en web)

	bool open = false;

	cout << "Tu vida no vale la pena y decides atracar el casino. A que hora daras el golpe?\n";

	cout << "1 - Por el dia\n";

	cout << "2 - Por la noche\n";

	cin >> answer;

	system("cls");

	if (answer._Equal("1"))

	{

		cout << "Entras al casino con un pasamontañas puesto y sacas de tu mochila un bate de beisbol, dispuesto a acabar con quien se ponga en tu camino.\n";

		cout << "Entonces, notas algo detras de ti, eres placado y tu vision se vuelve al suelo. Tienes a dos guardias encima, y no puedes respirar.\n";

		cout << "Mueres por asfixia. Quien decidiria atracar un casino con un bate a plena luz del dia?\n\nFinal idiota.\n";

	}

	else if (answer._Equal("2")) {

		cout << "Te metes por la puerta de emergencia del casino por la noche, dispuesto a atracarlo y recuperar lo que es tuyo.\n";

		cout << "Encuentras una serie de cables en la pared. Que haces?\n";

		cout << "1 - Los cortas.\n2 - Los sigues\n3 - Los ignoras";

		cin >> answer;

		if (answer._Equal("1")) {

			cout << "Intentas cortarlos con tus tijeras de peluqueria, y de repente notas un gran frio en tu mano. Tu vision se oscurece.\nTe has electrocutado.\n\nFinal electrico.\n";

		}

		else if (answer._Equal("2")) {

			cout << "Sigues los cables hasta llegar a una puerta. La abres, y descubres la sala de seguridad. Entonces, ves al guarda de seguridad durmiendo en su silla, frente al panel de control.\n";

			cout << "Que haras?\n1 - InteractFuas con el panel de seguridad.\n2 - Atacas al guarda.\n3 - Atas al guarda.\n4 - Te vas en silencio.";

			cin >> answer;

			system("cls");

			//Hacer mas historia aqui.

			if (answer._Equal("1")) {

				// Panel de seguridad

				cout << "Desactivas la seguridad del casino y te diriges a tu objetivo, la caja fuerte.\n";

				open = true;

				boveda(open);

			}

			else if (answer._Equal("2")) {

				// Atacar guarda

				cout << "Golpeas la cabeza del guarda con un hacha de guerra que llevabas en la mochila. Muere sin oponer resistencia, su rostro desfigurado y sangriento por el golpe.\n";

				cout << "Acto seguido desactivas la seguridad del casino y te diriges a tu objetivo, la caja fuerte.\n";

				open = true;

				system("wait");

				boveda(open);

			}

			else if (answer._Equal("3")) {

				// Atar guarda

				cout << "Decides atar al guarda a su silla para extorsionarlo y conseguir tu dinero. Mientras lo estas atando, escuchas un clac, y acto seguido un bam, y te empiezan a pitar los oidos.\n"

					<< "Miras hacia tu pecho y te das cuenta de que te ha disparado mientras lo atabas. Sientes un dolor punzante enorme.\n\nFinal rapido.";

			}

			else if (answer._Equal("4")) {

				// Irte

				cout << "Decides dejar la sala de seguridad e irte en silencio. Al darte la vuelta, te tropiezas y despiertas al guarda. Te dispara la cabeza y mueres instantaneamente.\n\nFinal torpe.";

			}

			else {

				cout << "No te decides y acabas muriendo de tanto pensar.\n\nFinal indeciso";

			}

		}

		else if (answer._Equal("3")) {

			cout << "Sigues tu camino hacia tu dinero. Entonces, unas luces rojas se encienden y empieza a sonar una alarma. No hay tiempo para pensar.\n";

			cout << "Empiezas a correr hasta que llegas a un punto con varios caminos. Cual escoges?\n1 - Por la derecha.\n2 - Por las escaleras.\n3 - Por la izquierda.\n";

			cin >> answer;

			system("cls");


			if (answer._Equal("1")) {

				cout << "Sigues por la derecha y encuentras la boveda al girar la esquina, pero hay dos guardas patrullando en frente de ella. Aun no te han visto, que haces?\n"

					<< "1 - Les atacas de frente.\n2 - Te comes un bocadillo.\n3 - Te mueres.\n4 - Vas hacia la puerta haciendo mogging.\n5 - Les pones un partido del Barcelona.\n";

				cin >> answer;

				if (answer._Equal("1")) {

					cout << "Te pones tus guantes de boxeo y te preparas para la batalla.\n";

					bossFight();

					if (battleVictory) {

						boveda(open);

					}

				}

				else if (answer._Equal("2")) {

					cout << "Te comes un bocadillo de lomo con queso. Estaba jodidamente delicioso.\n\nFinal bocadillo.";

				}

				else if (answer._Equal("3")) {

					cout << "Te mueres.\n\nFinal.";

				}

				else if (answer._Equal("4")) {

					cout << "Avanzas con seguridad y una mirada de cazador hacia la puerta. Ven que eres el alpha, y te abren la boveda. Consigues todo tu dinero y escapas del casino.\n\nFinal looksmaxxing.";

				}

				else if (answer._Equal("5")) {

					cout << "Coges tu televisor portatil de la mochila y les enseñas un partido del Barcelona. Los guardas se duermen.\n";

					boveda(open);

				}

				else {

					cout << "No te decides y acabas muriendo de tanto pensar.\n\nFinal indeciso.";

				}

			}

			else if (answer._Equal("2")) {

				cout << "Subes por las escaleras y ves a un guarda. Te das la vuelta para correr, te tropiezas y te abres la cabeza contra un escalon.\n\nFinal torpe.";

			}

			else if (answer._Equal("3")) {

				cout << "Sigues por la izquierda y entras a una habitacion. En la habitacion, hay tres guardas de seguridad. Sacan sus armas, y te empiezan a disparar. Mueres agujereado.\n\nFinal rapido.";

			}

			else {

				cout << "No te decides y acabas muriendo de tanto pensar.\n\nFinal indeciso.";

			}


		}

		else {

			cout << "No te decides y acabas muriendo de tanto pensar.\n\nFinal indeciso.";

		}

	}

	else {

		cout << "No te decides y acabas muriendo de tanto pensar.\n\nFinal indeciso";

	}


}


void lorePartII() {

	if (!flipTable1)
	{

		if (money >= 300)
		{
			if (answer._Equal("1"))
			{
				cout << "Quieres jugar otra vez, pero ves a dos personas de seguridad acercarse poco a poco.\n";
			}

			else if (answer._Equal("2"))
			{
				cout << "Decides marcharte con una gran cantidad de dinero. Antes de llegar a la salida, dos seguratas te detienen.\n";
			}
		}

		else if (money > 100 && money <= 250)
		{
			cout << "Te marchas a casa con una cantidad razonable de dinero. No es mucho, pero te permitira sobrevivir unas semanas mas.\n";
		}

		else if (money > 0 && money < 100)
		{
			cout << "Decides marchar del casino con perdidas. Tu intento por salvar tu vida ha sido en vano.\n";
		}

		else if (money == 0) {

			cout << "Se acabo. Has perdido todo, " << name << ". No hay nada que puedas hacer. O si?\n";
			cout << "1 - Rendirse\n";
			cout << "2 - Robar el casino\n";
			cin >> answer;

			if (answer._Equal("2"))
			{
				heist();
			}

			else cout << "Decides rendirte. No hay esperanza para ti. Final malo.\n";

		}

	}

	else if (flipTable1)
	{
		cout << "Se deja de oir el sonido de ambiente del casino. Ves como todo el mundo esta mirando directamente a tu mesa, destruida en el suelo.\nEl crupier te observa aterrado mientras ves como se acerca el personal de seguridad hacia ti. Preparate, " << name << ".\n";
		system("pause");
		bossFight();
	}


}

int main() {

	srand(time(NULL));

	lore();

	do
	{
		restart();

		playerBet();

		startingCards();

		checkCards();

		flipTable();

	} while (answer._Equal("1") && money < 250 && flipTable1 == false && money != 0);

	lorePartII();

}