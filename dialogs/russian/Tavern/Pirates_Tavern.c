// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос, " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Опять вопросы будем задавать?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Да нет, какие вопросы...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(PChar, "questTemp.Guardoftruth.Archy") && pchar.questTemp.Guardoftruth.Archy == "islatesorotavern")
			{
				link.l1 = "Послушай, "+npchar.name+", ты ничего не слыхал про человека по имени Мигель Дичозо? Говорят, его корабль видали у Исла Тесоро...";
				link.l1.go = "guardoftruth";
			}
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				link.l1 = "Послушай, "+npchar.name+", ты не видел в последнее время на Исла Тесоро Мигеля Дичозо?";
				link.l1.go = "tieyasal";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Слыхал. Этот испанский дон продал Акуле Додсону, когда тот ещё тут обитал, замечательный корабль, фрегат. Эх, такая посудина была - загляденье...";
			link.l1 = "Дай угадаю: уникальный по обводам корпуса и способный развивать скорость до шестнадцати узлов? И назывался он 'Санта-Квитерия'?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Насчет обводов и скорости ты совершенно прав, а вот назывался он по-другому: 'Сан-Мартин'. Акула целую кучу золота за него выложил этому проходимцу.";
			link.l1 = "Ты уверен, что 'Сан-Мартин', а не 'Санта-Квитерия'? И когда была совершена сделка? И почему ты назвал Дичозо проходимцем?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Совершенно уверен, что 'Сан-Мартин', потому что я лично ходил на верфь Алексуса и видел, как его работники отдирают доску с этим папистским именем от кормы. Акула Додсон назвал этот фрегат 'Фортуна' - куда более подходящее имя такому красавцу\nКупил он его незадолго до того, как был убит Блейз Шарп, зимой 1654 года. А почему я назвал дона Мигеля проходимцем? Да потому что этот корабль он украл у испанского военного флота, с базы Провиденсия. Додсон разыграл целый спектакль с пальбой и дымом на глазах у форта Сан-Хуан, он сам мне по пьяни рассказывал\nАкула пожертвовал пару дырявых люггеров, которые сжёг и затопил, инсценируя бой с фрегатом. А как спустилась темнота - отогнал 'Сан-Мартин' на Исла Тесоро. Акула получил корабль, а Дичозо - золото. В дальнейшем тот доложил своему начальству, что фрегат был потоплен в бою с пиратами, что подтвердил комендант форта Сан-Хуан.";
			link.l1 = "Вот как испанские доны набивают себе карманы! Каков прохиндей! Скажи, а это точно случилось зимой 1654 года? Может, всё-таки весной? И не имел ли этот фрегат следов потрепанности штормом?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Вроде зимой... да чёрт его знает, может, и весной. Я точно не помню. А потрепанным фрегат не был - совсем новенький, с иголочки.";
			link.l1 = "И где этот красавец-фрегат сейчас?";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "Тут тёмная история... Когда убили Блейза, все подозрения пали на Акулу: на трупе нашли его талисман - акулий зуб, которым, собственно, и зарезали Шарпа, и ещё по Исла-Тесоро слухи пошли, что Додсона видели в ту ночь у резиденции Блейза\nАкула, не дожидаясь чёрной метки, отбыл на Кубу к Черному Пастору, обменял у него свой фрегат на бриг и сгинул неведомо куда. До сих пор о нём ни слуху, ни духу. А фрегат тот Захария потом продал Вильяму Патерсону.";
			link.l1 = "А кто такой этот Патерсон?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "Ты что, никогда не слышал про Вилли Патерсона? Шотландец, недавно прибыл на Карибы, большая шишка, капитан Королевского флота, любимец самого полковника Фокса. Кстати, он ещё и с Джекманом делишки какие-то вертел. В общем, птица высокого полета. Ходит в составе мощной эскадры, и флагман у него - та самая 'Фортуна'.";
			link.l1 = "Ясно. Ты не знаешь, где сейчас Дичозо?";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			dialog.text = "Понятия не имею. После тех махинаций с 'Фортуной' я больше его на Исла Тесоро не видел и ничего о нём не слышал.";
			link.l1 = "Ладно, "+npchar.name+", спасибо за подробную информацию! Ты замечательный тавернщик! Побольше бы таких ребят... Бывай!";
			link.l1.go = "guardoftruth_7";
		break;
		
		case "guardoftruth_7":
			dialog.text = "Удачи, "+pchar.name+"!";
			link.l1 = "...";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			DialogExit();
			AddQuestRecord("Guardoftruth", "60_1");
			pchar.questTemp.Guardoftruth.Archy = "guadeloupe";
			// маленькая развлекуха
			pchar.quest.GuardOT_cabinattack.win_condition.l1 = "EnterToSea";
			pchar.quest.GuardOT_cabinattack.function = "GuardOT_PrepareCreateBandosInCabin";
		break;
		
		case "tieyasal":
			dialog.text = "Да вы, похоже, друг за дружкой гоняетесь, приятель. Да, Дичозо был тут, прямо, вот как ты сейчас стоишь. И точно так же справлялся о тебе - когда ты в последний раз был в Шарптауне.";
			link.l1 = "Чёрт возьми! Вот это новость... И где Мигель сейчас?";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "Понятия не имею. Он ушёл в море, а куда... он вроде что-то говорил о Блювельде. Вероятно, за тобой отправился, не иначе.";
			link.l1 = "Это не ты его в Блювельд отправил?";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			dialog.text = "Нет. Я всего лишь сообщил ему, что давно тебя не видел.";
			link.l1 = "Ясно. Ну что же, спасибо, дружище!";
			link.l1.go = "tieyasal_3";
		break;
		
		case "tieyasal_3":
			DialogExit();
			AddQuestRecord("Tieyasal", "3");
			npchar.quest.tieyasal = "true";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1 = "location";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1.location = "Bermudes";
			pchar.quest.Tieyasal_ITAttack.function = "Tieyasal_CreateITShips";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}