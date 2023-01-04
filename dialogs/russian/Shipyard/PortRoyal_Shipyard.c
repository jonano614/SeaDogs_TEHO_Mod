// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Совсем недавно вы пытались задать мне вопрос...", "У себя на верфи, да и вообще в городе, я таких однообразно любознательных не видал.",
                          "Ну что за вопросы? Моё дело - корабли строить, давайте этим и займёмся.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить."), "Хм, что-то с памятью моей стало...",
                      "Хм, однако...", "Давайте...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx"))
            {
				if (pchar.questTemp.Mtraxx == "silk_2" || pchar.questTemp.Mtraxx == "silk_3")
				{
					link.l1 = "Я знаю, что на вашей верфи улучшают ходовые качества кораблей: скорость и ход в бейдевинд. Для этой работы используется редкий товар - корабельный шёлк. Вам... было бы интересно поговорить об этом?";
					link.l1.go = "mtraxx";
				}
			}
		break;
		
		// Addon 2016-1 Jason пиратская линейка
		case "mtraxx":
            dialog.text = "Молодой человек, изъясняйтесь понятнее. Что у вас ко мне за дело? Вам нужно провести работы по улучшению вашего корабля? Давайте обсудим.";
			link.l1 = "Нет, я имею в виду другое. Вы используете в работе товар, который нельзя приобрести в магазинах или где-то заказать. А я хочу вам предложить то, в чём нуждается ваше производство.";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
            dialog.text = "Так-так... Кхм... Вы вообще в курсе, что купля-продажа данного товара в нашей колонии находится под контролем властей? Вы можете предоставить мне шёлк для работы, но продавать не имеете права, так же как и я купить его у вас. За это полагается крупный штраф.";
			link.l1 = "Но мы же не в магазине и не на таможне...";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
            dialog.text = "Весь шёлк для работы я получаю либо от клиентов, либо приобретаю в ограниченных количествах по специальному разрешению губернатора. Ещё вопросы есть? Если нет - не мешайте работать.";
			link.l1 = "Гм... Ладно. Всего доброго, мастер.";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            DialogExit();
			AddQuestRecord("Roger_2", "5");
			pchar.questTemp.Mtraxx = "silk_4";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
