// лидер клана ривадос - Черный Эдди
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Что тебе нужно на территории ривадос, белый человек?";
			link.l1 = "Я просто знакомлюсь с людьми. Извини, если помешал.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "Friend":
			dialog.text = "Рад приветствовать друга ривадос и просто хорошего человека! Чимисет рассказал о том, что ты для него сделал. Все ривадос, в том числе и я, в неоплатном долгу перед тобой. Разреши представиться: Эдвард Блэк, он же Чёрный Эдди, глава клана ривадос.";
			link.l1 = ""+GetFullName(pchar)+". Хотя, думаю, Чимисет уже называл моё имя. Он обещал подробно рассказать обо мне...";
			link.l1.go = "Friend_1";
		break;
		
		case "Friend_1":
			dialog.text = "И он это сделал. Теперь ты можешь свободно посещать все корабли ривадос без каких-либо ограничений. Охрана не будет препятствовать, и мы будем рады видеть тебя в гостях. Но будь острожен с нарвалами: они уже наверняка знают, что это именно ты спас Чимисета, и им это весьма не понравится, потому как они наши враги.";
			link.l1 = "Учту. Спасибо за тёплый приём, Эдди! А теперь позволь мне поговорить с Чимисетом.";
			link.l1.go = "Friend_2";
		break;
		
		case "Friend_2":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "goto", "goto1", "LSC_EddyStay", -1);
			AddSimpleRumourCityTip("Говорят, что вы дружны с самим Чёрным Эдди, главой ривадос. И как это вы умудрились?", "LostShipsCity", 10, 1, "LSC", "");
			AddSimpleRumourCityTip("Ривадос утверждают, что вы их друг. Это так, сударь?", "LostShipsCity", 10, 1, "LSC", "");
			AddSimpleRumourCityTip("Говорят, нарвалы косо посматривают на вас из-за ваших тесных взаимоотношений с ривадос. Вас это не беспокоит?", "LostShipsCity", 10, 1, "LSC", "");
		break;
		
		// --> информационный блок
		case "Total_info": // стал другом
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "Белый брат? Ты жив? Я очень рад этому! Значит, нарвалы солгали, говоря всем, что ты утонул...";
				link.l1 = "Я тоже рад тебя видеть, Эдди. А нарвалы слегка преувеличили - я тонуть и не собирался.";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			dialog.text = "Рад тебя видеть, "+pchar.name+"? Какие новости?";
			if (!CheckAttribute(npchar, "quest.natan"))
			{
				link.l1 = "Эдди, ты не знаешь, есть ли на острове такой человек - Натаниэль Хоук? По моим сведениям, он должен быть тут.";
				link.l1.go = "natan";
			}
			if (!CheckAttribute(npchar, "quest.rivados"))
			{
				link.l2 = "Расскажи мне подробнее о клане ривадос.";
				link.l2.go = "rivados";
			}
			link.l9 = "Да никаких особых новостей нет. просто зашёл тебя поприветствовать.";
			link.l9.go = "exit";
		break;
		
		case "natan":
			dialog.text = "Натаниэль Хоук? Нет, такого я не знаю. Ни на кораблях ривадос, ни в нейтральной зоне его нет и никогда не было. Только если у нарвалов, но тут я сказать ничего не могу, поскольку на их территорию мы не заходим.";
			link.l1 = "Понятно...";
			link.l1.go = "exit";
			npchar.quest.natan = "true";
			NextDiag.TempNode = "Total_info";
		break;
		
		case "rivados":
			dialog.text = "Клан ривадос появился очень давно, и был первым кланом на Острове. Более полувека назад экспедиция адмирала де Бетанкура пересекала море, именуемое Карибским, на нескольких больших кораблях. Трюмы одного из них, 'Тартаруса', были наполнены несколькими сотнями чернокожих невольников, захваченных на их родине в Африке, и обращённых в рабов. Среди них был один человек по имени Педро Ривадос\nОн сумел освободить от кандалов несколько десятков рабов и поднял восстание. К сожалению, остальные невольники не смогли в должном количестве примкнуть к его отряду, и бунт захлебнулся. Испанцы жестоко расправились с Ривадосом - привязали его в трюме к переборке и оставили умирать от жажды и голода. В тот же вечер погода испортилась, и эскадру захватил мощный шторм\nПосле нескольких дней борьбы со стихией, два уцелевших корабля - 'Сан-Августин' и 'Тартарус' сели на дно в центральной части Острова. Во время всей этой кутерьмы погибло много как белых, так и чернокожих, но ещё больше осталось в живых. Бывшие невольники стали жить большой дружной семьёй и назвали свой новый род 'ривадос', в честь казнённого борца за свободу Педро Ривадоса.";
			link.l1 = "Очень интересная история... Спасибо!";
			link.l1.go = "exit";
			npchar.quest.rivados = "true";
			NextDiag.TempNode = "Total_info";
		break;
		// <-- информационный блок
		
		case "capper":
			dialog.text = "Что нужно тебе, белый человек, на территории ривадос?";
			link.l1 = "Меня зовут "+GetFullName(pchar)+", и я пришёл с официальным визитом от адмирала Додсона. Мне нужно поговорить с Чёрным Эдди. Как я понимаю, это ты.";
			link.l1.go = "capper_1";
		break;
		
		case "capper_1":
			dialog.text = "Да, я Эдвард Блэк, или Чёрный Эдди. Говори, что адмиралу нужно от меня.";
			link.l1 = "В тюрьме на 'Тартарусе' находится ваш человек по имени Чимисет. Адмирал хочет его освободить.";
			link.l1.go = "capper_2";
		break;
		
		case "capper_2":
			dialog.text = "Это очень хорошая новость. Чимисет - наш духовный лидер, все ривадос огорчены его пленением. Но как я понимаю, адмирал что-то хочет за его свободу?";
			link.l1 = "Ничего. Он просто желает его освободить в качестве... жеста доброй воли. Однако с этим возникли непредвиденные трудности...";
			link.l1.go = "capper_3";
		break;
		
		case "capper_3":
			dialog.text = "Продолжай, белый человек.";
			link.l1 = "Бывший боцман адмирала, а ныне - тюремщик Чад Каппер, перешёл на сторону нарвалов и вышел из-под контроля адмирала. Мы узнали, что Чад готовит убийство Чимисета. Адмирал не желает этого допустить. Мы предлагаем вам провести совместную операцию по ликвидации предателя и освобождению вашего человека.";
			link.l1.go = "capper_4";
		break;
		
		case "capper_4":
			dialog.text = "Твои слова звучат странно, но продолжай. Чимисет в опасности?";
			link.l1 = "Да. Чад собирается его убить. Каппер намерен при помощи нарвалов захватить власть на Острове. Чтобы спасти Чимисета, нужно немедленно действовать, пока Чад ничего не подозревает. Адмирал снял всю палубную охрану с 'Тартаруса' - вход на него свободен. Вот ключ, который открывает двери в тюрьму. Держи.";
			link.l1.go = "capper_5";
		break;
		
		case "capper_5":
			RemoveItems(pchar, "key_capper", 1);
			dialog.text = "";
			link.l1 = "Собери своих бойцов, отправляйся на 'Тартарус' и освободи Чимисета. У тебя для этого есть все возможности.";
			link.l1.go = "capper_6";
		break;
		
		case "capper_6":
			dialog.text = "Это похоже на ловушку... А если там ждет засада? Если адмирал решил таким способом нанести удар по ривадос? Почему он сам не ликвидирует Каппера?";
			link.l1 = "Додсон считал, что жизнь Чимисета вам дорога... Со своей стороны он сделал достаточно - передал тебе ключ и снял охрану. Вам осталось только войти, расправиться с Чадом и освободить своего человека. Даю тебе честное слово, что никакого подвоха нет. Да, и ещё: адмирал хочет в обмен на Чимисета получить голову Каппера. Мы поняли друг друга?";
			link.l1.go = "capper_7";
		break;
		
		case "capper_7":
			dialog.text = "Жизнь Чимисета важна для ривадос, как никакая другая. Мы отправимся на 'Тартарус' немедленно. Ты останешься здесь в качестве заложника. Если нас в тюрьме будет подстерегать засада адмирала - ты узнаешь на своей шкуре, что такое гнев ривадос\nЗикомо! Встань у двери и следи за нашим гостем, чтобы он не покинул пределов каюты. А я возглавлю наступление на 'Тартарус'!";
			link.l1 = "Удачи, Эдди. И помни: мне нужна голова Чада Каппера!";
			link.l1.go = "capper_8";
		break;
		
		case "capper_8":
			DialogExit();
			chrDisableReloadToLocation = true;//закрыть локацию
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "LSC_ZikomoNearDoor", 10.0);
			NextDiag.CurrentNode = "chimiset";
		break;
		
		case "chimiset":
			dialog.text = "Чимисет свободен! Ты не солгал, белый человек, и за свободу и жизнь Чимисета я готов назвать тебя другом ривадос!";
			link.l1 = "Я очень рад. Чад Каппер мёртв?";
			link.l1.go = "chimiset_1";
		break;
		
		case "chimiset_1":
			dialog.text = "Я вынужден просить извинения, белый друг: ты сделал всё со своей стороны, а мы подвели... я подвёл! Проклятый Каппер сбежал. Вместе с ним в тюрьме были два нарвала. Мы их уничтожили, но гнусный тюремщик, отстреливаясь, выскочил через дверь внизу и ушёл от нас вплавь на территорию нарвалов.";
			link.l1 = "Эх... Неужели ты не знал, что у 'Тартаруса' два выхода?";
			link.l1.go = "chimiset_2";
		break;
		
		case "chimiset_2":
			dialog.text = "Мы не подумали об этом. Мы атаковали со стороны палубы...";
			link.l1 = "Жаль. Я рассчитывал получить голову Чада. Очень, очень плохо! Теперь он будет и дальше нам вредить.";
			link.l1.go = "chimiset_3";
		break;
		
		case "chimiset_3":
			dialog.text = "Я признаю свою вину. Но мы не могли последовать за ним на корабли вражеского клана... Вместо головы Чада ты получишь дружбу и уважение ривадос. Отныне ты можешь всегда рассчитывать на нашу поддержку\nНаши корабли теперь открыты тебе для свободного прохода. Мудрость Чимисета, освобождённого с твоей помощью, тоже тебе пригодится. Поговори с ним, если у тебя в чем есть нужда. Также передай адмиралу мои заверения, что я оценил его поступок.";
			link.l1 = "Хорошо.";
			link.l1.go = "chimiset_4";
		break;
		
		case "chimiset_4":
			dialog.text = "Погоди! Мы упустили Чада, но я нашёл у него на столе несколько бумаг, которые он изучал, когда мы ворвались. Он бросил их, а я собрал. Вот они. Может, написанное там окажется для тебя полезным, белый друг.";
			link.l1 = "Ха! Возможно, и окажется - Чад слишком многое доверяет бумаге...";
			link.l1.go = "chimiset_5";
		break;
		
		case "chimiset_5":
			dialog.text = "Ты всегда желанный гость у нас, белый друг. Все ривадос будут оповещены об этом. Удачи тебе!";
			link.l1 = "И тебе тоже, Эдди...";
			link.l1.go = "chimiset_6";
		break;
		
		case "chimiset_6":
			DialogExit();
			LAi_ActorGoToLocator(npchar, "goto", "goto1", "LSC_EddyStay", -1);
			sld = CharacterFromID("Zikomo");
            LAi_SetWarriorType(sld);
			LAi_warrior_SetStay(sld, true);
			LAi_warrior_DialogEnable(sld, true);
			GiveItem2Character(pchar, "letter_chad");
			ChangeItemDescribe("letter_chad", "itmdescr_letter_aeva");
			GiveItem2Character(pchar, "letter_chad_1");
			ChangeItemDescribe("letter_chad_1", "itmdescr_letter_axel");
			pchar.questTemp.LSC.rvd_friend = "true"; //флаг на проход по кораблям ривадос
			pchar.questTemp.Saga.SharkHunt = "dodson_whiskey"; // к Акуле
			sld = CharacterFromID("Dodson");
			sld.dialog.currentnode = "Chad_escape"; // ноду Акуле
			AddQuestRecord("SharkHunt", "33");
			LocatorReloadEnterDisable("LostShipsCity_town", "reload48", true); // закрыть вход к Дональду Гринспи
			AddSimpleRumourCityTip("Слыхали? Наглость ривадос превзошла все ожидания: напали посреди бела дня на тюрьму адмирала и освободили своего колдуна!", "LostShipsCity", 3, 2, "LSC", "");
			AddSimpleRumourCityTip("Подумать только - ривадос осмелились напасть на 'Тартарус'! Говорят, что тюремщик, Чад Каппер, бежал и скрылся у нарвалов...", "LostShipsCity", 3, 2, "LSC", "");
			AddSimpleRumourCityTip("Наглость - второе счастье, не правда ли? Напасть на военный объект адмирала! Да, Чёрный Эдди, похоже, набирает силу...", "LostShipsCity", 3, 2, "LSC", "");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}