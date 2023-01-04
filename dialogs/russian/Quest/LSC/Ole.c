// Оле Кристиансен - Белый Мальчик
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Что вам надо?";
			link.l1 = "Ничего.";
			NextDiag.TempNode = "First time";
		break;
		
		// в магазине - первая встреча
		case "store":
			dialog.text = "Ой... Здравствуй, дяденька. У тебя есть белая бусинка? Дай белую бусинку...";
			link.l1 = "Хм. Добрый день. Это вы... кхе, это ты - Белый Мальчик?";
			link.l1.go = "store_1";
		break;
		
		case "store_1":
			dialog.text = "Бусинка! Белая бусинка для белого мальчика! У тебя есть белая бусинка, дяденька?";
			if (CheckCharacterItem(pchar, "jewelry52"))
			{
				link.l1 = "Хм. Бусинок у меня нет, но я могу тебе дать вот эту жемчужину. Она белая, и совсем как бусинка. Подойдёт?";
				link.l1.go = "store_2";
			}
			link.l2 = "Нет у меня никаких бусинок, ни белых, ни красных. Я не девочка и не индеец, чтобы бусы носить. Скажи лучше...";
			link.l2.go = "pearl";
			sld = characterFromId("Axel");
			sld.quest.ole_pearl = "true";
		break;
		
		case "pearl":
			dialog.text = "Бусинка! Белая бусинка! Нет белой бусинки - я не буду разговаривать. Плохой дяденька... Дай бусинку!";
			link.l1 = "Тьфу ты! Вот ведь юродивый! Верно Чимисет и Змеиный Глаз сказали - слаб на голову... Какая ему бусинка нужна?";
			link.l1.go = "exit";
			NextDiag.TempNode = "pearl_repeat";
		break;
		
		case "pearl_repeat":
			dialog.text = "Дайте бусинку, дяденька. Хороший дяденька... Белую бусинку!";
			if (CheckCharacterItem(pchar, "jewelry52"))
			{
				link.l1 = "Вот, держи свою бусинку. Ты же её хотел, так?";
				link.l1.go = "store_2";
			}
			link.l2 = "Ох, ну что же это за наказание такое...";
			link.l2.go = "exit";
			NextDiag.TempNode = "pearl_repeat";
		break;
		
		case "store_2":
			RemoveItems(pchar, "jewelry52", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "Да, да! Это она! Дяденька дал белую бусинку! Спасибо, ты добрый человек! Теперь у Оле есть ещё одна бусинка. Скоро я увижу маму...";
			link.l1 = "Я рад за тебя. Ну, а теперь мы можем поговорить?";
			link.l1.go = "store_3";
			sld = characterFromId("Axel");
			DeleteAttribute(sld, "quest.ole_pearl");
		break;
		
		case "store_3":
			dialog.text = "Конечно, добрый человек. Ты же добрый человек, дяденька? Тогда мы станем друзьями. Оле будет рад говорить с тобой. Как тебя зовут?";
			link.l1 = "Меня зовут "+pchar.name+". Оле, мне про тебя рассказал один человек, его уже нет здесь. Так вот, он сказал, что ты помог ему, и что сможешь помочь мне.";
			link.l1.go = "store_4";
		break;
		
		case "store_4":
			dialog.text = "Дяденька дал Оле бусинку - дяденька добрый человек. Оле любит помогать добрым людям. Здесь мало добрых людей - кругом плохие дяденьки. Я помогу тебе, конечно. Я люблю помогать!";
			link.l1 = "Просто замечательно! Ну, раз мы с тобой подружились, Оле, ответь на мой вопрос: ты помнишь человека с красной кожей, в роскошном головном уборе из птичьих перьев? Это он сказал, что ты спас его, когда был ещё подростком.";
			link.l1.go = "store_5";
		break;
		
		case "store_5":
			dialog.text = "Я помню этого дяденьку. Это добрый человек. Я спас его. Я отвел его к статуе. А вот недавно я спас ещё одного доброго человека, из трюма с едой, от злых дядек адмирала. Они бы убили его, если бы нашли там. Я хотел и его отвести к статуе, но он отказался. Совсем отказался.";
			link.l1 = "Из трюма с едой? Хех, кажется, я знаю, что это за трюм... Да и про дяденьку догадываюсь. Скажи, Оле, кто этот второй спасённый тобой человек?";
			link.l1.go = "store_6";
		break;
		
		case "store_6":
			dialog.text = "Его зовут дядя Натан. Он очень, очень болен. Он едва мог ходить, когда Оле нашёл его в трюме.";
			link.l1 = "Охотно верю... Странно, что он вообще жив остался.";
			link.l1.go = "store_7";
		break;
		
		case "store_7":
			dialog.text = "Нет, не странно. Это потому что я его нашёл и дал выпить огненного рому. Я заплыл в пролом, потому что на том корабле есть еда. Злые дяди запирают дверь в трюм, но я всегда её открываю - хи-хи-хи... Глупые злые дядьки. Они приманивают туда крабов, я знаю. Плохие люди\nЯ приплыл - а там лежит дядя Натан. Ему было очень плохо. У меня был огненный ром - я дал ему попить, и ему стало лучше. Потом я дал ему настойку из трав - я всегда такую с собой ношу, чтобы выпить, если страшный краб укусит Оле. Мне так сказал добрый дядя Чимисет...";
			link.l1 = "Ты дал ему противоядие и ром? Хех, напрасно тебя дурачком тут считают. Ты молодец, Оле.";
			link.l1.go = "store_8";
		break;
		
		case "store_8":
			dialog.text = "Злые дяди считают Оле дурачком, и дразнят: Оле-дурачок... Оле не дурачок - ему нужно собрать все белые бусинки, иначе мама прогонит его. Ты мне потом дашь ещё бусинку?";
			link.l1 = "Кхм... Конечно, Оле, мы же друзья. Скажи, а как ты собирался отвести Хоука... дядю Натана, к статуе? Дядя Чимисет сказал мне, что она утонула вместе с кораблём и сейчас на дне...";
			link.l1.go = "store_9";
		break;
		
		case "store_9":
			dialog.text = "Статуя на дне. Оле знает. Но она неглубоко, и туда дядю Натана мог бы отправить добрый дядя Хенрик. Дядя Хенрик знает, как можно ходить по дну. Но на дне много страшных крабов. Оле боится крабов. Они больно кусаются.";
			link.l1 = "Дядя Хенрик? А это кто?";
			link.l1.go = "store_10";
		break;
		
		case "store_10":
			dialog.text = "Дядя Хенрик живет среди злых дядей нарвалов. Его все знают. Он всё умеет. Он умеет ходить по дну и научил злых дядей нарвалов спускаться на дно. Дядя Хенрик добрый, он дал Оле белую бусинку.";
			link.l1 = "Как же нарвалы пускают тебя к себе? Или для тебя проход открыт?";
			link.l1.go = "store_11";
		break;
		
		case "store_11":
			dialog.text = "Хи-хи-хи... Злые дядьки нарвалы не пускают Оле, но Оле сам ночью может зайти в любое помещение на их кораблях. Они большие и шумные, а Оле тихий и осторожный. А дядю Хенрика я встретил, когда плавал около корабля, с которого дядя Хенрик спускается на дно. Дядя Хенрик дал Оле бусинку, и мы подружились.";
			link.l1 = "Очень интересно... Я тоже хочу подружиться с дядей Хенриком.";
			link.l1.go = "store_12";
		break;
		
		case "store_12":
			dialog.text = "Ты хочешь спуститься на дно и пойти к статуе? Она там, в разломе старого корабля. Там много больших страшных крабов. Ты не боишься крабов? Они могут укусить.";
			link.l1 = "Нет, я не боюсь крабов. Я уже убил одного, так что пускай они меня боятся.";
			link.l1.go = "store_13";
		break;
		
		case "store_13":
			dialog.text = "О, "+pchar.name+" очень храбрый! Тогда тебе надо идти к дяде Хенрику - он научит тебя ходить по дну и ты перебьёшь всех плохих крабов. И найдёшь там ещё одну белую бусинку для Оле. Правда?";
			link.l1 = "Конечно, найду. Только сначала надо найти дядю Хенрика.";
			link.l1.go = "store_14";
		break;
		
		case "store_14":
			dialog.text = "А зачем его искать? Он живёт на корабле с именем 'Сан-Габриэль', в мастерской. Но злые дядьки нарвалы могут тебя не пустить.";
			link.l1 = "Со злыми дядьками нарвалами я как-нибудь договорюсь. И последний вопрос: где сейчас дядя Натан? Дело в том, Оле, что я его искал и пришёл сюда, чтобы увидеть его.";
			link.l1.go = "store_15";
		break;
		
		case "store_15":
			dialog.text = "Я спрятал дядю Натана в своём убежище на корабле 'Фернанда'. Он стоит далеко, и там никого нет. Все думают, что он скоро утонет, потому что сломан напополам, а Оле знает, что не утонет. Я спас дядю Натана и привёз его туда. Теперь дядя Натан живет там\nОн ещё очень болен, и всё время пьёт огненный ром. Он почти не может ходить, и не может поднять ничего тяжелее пяти фунтов. Мне жаль дядю Натана, я ношу ему огненный ром из сундуков и покушать из трюма злых дядек адмирала. А ещё я жарю ему крыс, которых ловлю. Очень вкусные крысы!";
			link.l1 = "Вкусные крысы? Ну-ну. Так Натан сейчас на корабле... как ты сказал - 'Фернанда'? Я такого не знаю...";
			link.l1.go = "store_16";
		break;
		
		case "store_16":
			dialog.text = "Дяденька "+pchar.name+", я же только что сказал - он стоит далеко. До него нельзя дойти, можно только доплыть. Там с кормы есть дверь, но дядя Натан её закрывает. Это Оле его научил. Но если ты друг дяди Натана, то я скажу тебе, как открыть: постучи ему вот так: тук-тук... тук-тук. И он откроет.";
			link.l1 = "Я запомню. Спасибо, Оле! Ты очень мне помог! Прямо и не знаю, как тебя благодарить.";
			link.l1.go = "store_17";
		break;
		
		case "store_17":
			dialog.text = "Принеси мне ещё одну белую бусинку. Когда найдёшь, конечно.";
			link.l1 = "Ах, да! Белые бусинки! Хорошо. Ещё увидимся, Оле!";
			link.l1.go = "store_18";
		break;
		
		case "store_18":
			DialogExit();
			LAi_SetLoginTime(npchar, 12.0, 21.99);
			LAi_SetCitizenType(npchar);
			LAi_group_MoveCharacter(npchar, "LSC_CITIZEN");
			sld = characterFromId("Nathaniel");
			sld.dialog.currentnode = "diffindoor";
			sld.greeting = "Nathaniel_ill"; // ноду и вякалку Натану
			pchar.questTemp.LSC.DiffIndoor = "true"; //атрибут прохода к Натану
			pchar.questTemp.LSC = "mechanic"; // флаг на разговор с Механиком
			NextDiag.CurrentNode = "ole";
			AddQuestRecord("LSC", "6");
		break;
		
		case "ole":
			dialog.text = "А, дядя "+pchar.name+"! Рад вас видеть! Как дела?";
			link.l1 = "Спасибо, Оле, всё хорошо. Я тоже рад встрече с тобой.";
			link.l1.go = "exit";
			link.l2 = "Послушай, Оле, ты говорил, что пираты адмирала закрывают дверь в трюм, но ты всегда её открываешь... Да и сундуки тут все на замках, а ты говорил, что забираешь из них ром для дяди Натана. Как тебе всё это удаётся?";
			link.l2.go = "lock";
			NextDiag.TempNode = "ole";
		break;
		
		case "lock":
			dialog.text = "У Оле есть набор хороших ключиков. Они подходят ко всем замкам на сундуках и дверях. Хотя нет, не ко всем. Некоторые открыть нельзя, но большинство - можно. Оле нашёл их в каюте злого дяди-нарвала Юргена. Он целыми днями стоит у печки и стучит молотком. Он делает замки и ключи. А ещё он делает и чинит большие и страшные мушкеты для злых нарвалов.";
			link.l1 = "Понятно. Оле, а ты не можешь продать мне эти ключики? Я бы заплатил...";
			link.l1.go = "lock_1";
		break;
		
		case "lock_1":
			dialog.text = "Хорошо, дядя "+pchar.name+", я продам тебе эти ключики. Только один себе оставлю, который открывает дверь в кладовку адмирала. Там много вкусной еды и есть ром для дяди Натана. Всё равно в сундуках нет больше бусинок и рома.";
			link.l1 = "Сколько ты за них хочешь?";
			link.l1.go = "lock_2";
		break;
		
		case "lock_2":
			dialog.text = "Скажи сначала, дядя "+pchar.name+", а у тебя есть большой корабль?";
			link.l1 = "Да, есть. Но он не здесь, он на Большой земле. Но я скоро уйду с острова, а потом вернусь сюда на этом корабле за дядей Натаном.";
			link.l1.go = "lock_3";
		break;
		
		case "lock_3":
			dialog.text = "За дядей Натаном? Ой, как хорошо! Тогда вот что: пообещай мне, что когда вернёшься на большом корабле, то заберёшь меня отсюда и позволишь плавать с собой, пока мне не надоест. Я буду полезным, я умею ловить и жарить крыс... И ещё дай пять белых бусинок. И я отдам тебе ключики.";
			if (GetCharacterItem(pchar, "jewelry52") >= 5)
			{
				link.l1 = "Отлично! Вот твои белые бусинки. Держи.";
				link.l1.go = "lock_4";
			}
			link.l2 = "Ловить и жарить крыс? Хех! Интересное умение. Хорошо, Оле, договорились. Я принесу тебе пять бусинок и дам обещание.";
			link.l2.go = "exit";
			NextDiag.TempNode = "ole_1";
		break;
		
		case "ole_1":
			dialog.text = "А, дядя "+pchar.name+"! Рад тебя видеть! Как дела?";
			link.l1 = "Спасибо, Оле, всё хорошо. Я тоже рад встрече с тобой.";
			link.l1.go = "exit";
			if (GetCharacterItem(pchar, "jewelry52") >= 5)
			{
				link.l2 = "Я принёс тебе пять белых бусинок за ключики.";
				link.l2.go = "lock_4";
			}
			NextDiag.TempNode = "ole_1";
		break;
		
		case "lock_4":
			RemoveItems(pchar, "jewelry52", 5);
			PlaySound("interface\important_item.wav");
			dialog.text = "Бусинки! Белые бусинки! Дяденька "+pchar.name+" дал Оле бусинки! Скоро я увижу тебя, мамочка!.. Дядя "+pchar.name+", ты обещаешь, что возьмёшь меня на свой корабль, когда вернёшься?";
			link.l1 = "Обещаю, Оле. Я ещё никогда не ел жареных крыс. Я возьму тебя с собой.";
			link.l1.go = "lock_5";
		break;
		
		case "lock_5":
			GiveItem2Character(pchar, "keys_skel");
			AddCharacterExpToSkill(pchar, "Sneak", 200);
			dialog.text = "Спасибо, спасибо, добрый дядя "+pchar.name+"! Вот твои ключики. Пользоваться ими просто: вставляешь по очереди и крутишь - какой-нибудь да и откроет. Если не открыл ни один - значит, замок очень хитрый и обязательно нужен ключ именно от него.";
			link.l1 = "Понятно. Думаю, что разберусь, что к чему.";
			link.l1.go = "lock_6";
		break;
		
		case "lock_6":
			dialog.text = "Подожди, дядя "+pchar.name+"! У меня есть один ключ, красивый-красивый и очень сложный. Злой дядя Юрген таких не делает. Что он открывает - не знаю, я не нашёл такого сундука или двери. Но может ты найдёшь? Посмотри, какой красивый ключик! Ты таких раньше не видел.";
			link.l1 = "Покажи... Да, ключ интересный. Но какой толк от ключа, если не знаешь, от какого он замка?";
			link.l1.go = "lock_7";
		break;
		
		case "lock_7":
			dialog.text = "Дядя "+pchar.name+", ты очень странный. Какой толк? Если есть ключ, значит, есть замок. Если есть замок - должен быть ключ. Это же просто. Вот ключ. Значит, есть и замок. Ключ я нашёл на Острове, значит, и замок тоже на Острове. Иначе и быть не может. А как иначе? Это сложный ключ, такими ключами запирают только что-то ценное. Оле знает.";
			link.l1 = "Честное слово, ты меня повеселил. Хорошо, я куплю у тебя и этот ключик. Ты хочешь за него бусинки, да?";
			link.l1.go = "lock_8";
		break;
		
		case "lock_8":
			dialog.text = "Да, Оле хочет пять белых бусинок. Ты дашь мне их, дядя "+pchar.name+"?";
			if (GetCharacterItem(pchar, "jewelry52") >= 5)
			{
				link.l1 = "Вот, возьми свои бусинки.";
				link.l1.go = "key";
			}
			link.l2 = "У меня пока их нет, но я обязательно принесу.";
			link.l2.go = "exit";
			NextDiag.TempNode = "ole_2";
		break;
		
		case "key":
			RemoveItems(pchar, "jewelry52", 5);
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "sant_anna_key");
			AddCharacterExpToSkill(pchar, "Fortune", 200);
			dialog.text = "Бусинки! Белые бусинки для белого мальчика! Для его мамочки! Вот, дядя "+pchar.name+", возьми ключик. А замок ты найдёшь, Оле знает. Ты храбрый, ты даже не боишься страшных крабов.";
			link.l1 = "Ой, не смеши меня, Оле! Спасибо за ключ. Ещё увидимся!";
			link.l1.go = "exit";
			NextDiag.TempNode = "ole_3";
		break;
		
		case "ole_2":
			dialog.text = "А, дядя "+pchar.name+"! Рад тебя видеть! Как дела?";
			link.l1 = "Спасибо, Оле, всё хорошо. Я тоже рад тебя видеть.";
			link.l1.go = "exit";
			if (GetCharacterItem(pchar, "jewelry52") >= 5)
			{
				link.l2 = "Я принёс тебе пять белых бусинок за твой ключ.";
				link.l2.go = "key";
			}
			NextDiag.TempNode = "ole_2";
		break;
		
		case "ole_3":
			dialog.text = "А, дядя "+pchar.name+"! Рад тебя видеть! Как дела?";
			link.l1 = "Спасибо, Оле, всё хорошо. Я тоже рад встрече с тобой.";
			link.l1.go = "exit";
			NextDiag.TempNode = "ole_3";
		break;
		
		case "return":
			dialog.text = "Ой, дядя "+pchar.name+", ты вернулся! Ты вернулся на большом корабле! Ты возьмёшь меня к себе? Дядя "+pchar.name+", ты обещал, помнишь?";
			link.l1 = "Конечно, помню, Оле. Добро пожаловать на борт! Думаю, для крыс наступили чёрные дни, ха-ха!";
			link.l1.go = "return_1";
			link.l2 = "Да ну? И когда такое было? Я что-то таких обещаний не припомню...";
			link.l2.go = "return_3";
		break;
		
		case "return_1":
			dialog.text = "Спасибо, дяденька! Оле будет полезным тебе, вот увидишь! Ой, может, я скоро увижу мамочку? Всё, я побежал!";
			link.l1 = "Можешь не спешить, Оле, и спокойно собрать вещи. Я ещё не отчаливаю...";
			link.l1.go = "return_2";
		break;
		
		case "return_2":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "LSC_SetOlePassenger", 10.0);
		break;
		
		case "return_3":
			dialog.text = "Ты обещал, ты обещал! Ты обещал забрать Оле! Плохой дядька! Обманул Оле! Плохой дядька!";
			link.l1 = "...";
			link.l1.go = "return_4";
		break;
		
		case "return_4":
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorRunToLocation(npchar, "reload", "reload45", "none", "", "", "", 20.0);
			ChangeCharacterComplexReputation(pchar, "nobility", -5);
			ChangeCharacterComplexReputation(pchar, "authority", -3);
			if (GetCharacterIndex("Mary") != -1) // Мэри
			{
				sld = characterFromId("Mary");
				LAi_SetActorType(sld);
				LAi_ActorDialog(sld, pchar, "", -1, 0);
			}
			else // иначе завершение
			{
				chrDisableReloadToLocation = false;
				LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			}
		break;
		
		// Блудный сын
		case "givemepearl":
			dialog.text = "Дяденька, дяденька... Мне нужна ещё одна белая бусинка. Ну пожалуйста, дай Оле белую бусинку!";
			if (CheckCharacterItem(pchar, "jewelry52"))
			{
				link.l1 = "Я знал, что ты будешь её просить. Вот, держи свою бусинку. Ты доволен?";
				link.l1.go = "givemepearl_yes";
			}
			link.l2 = "Ох, ну что же это за наказание такое... Нет у меня больше бусинок, Оле, нету!";
			link.l2.go = "givemepearl_no";
			DeleteAttribute(npchar, "pearl_date");
		break;
		
		case "givemepearl_yes":
			RemoveItems(pchar, "jewelry52", 1);
			PlaySound("interface\important_item.wav");
			AddCharacterExpToSkill(pchar, "Fortune", 50);
			dialog.text = "Спасибо! Добрый, добрый дядя "+pchar.name+"! У Оле есть ещё одна бусинка, осталось совсем немного! И можно будет ехать к маме...";
			link.l1 = "Ох, и в кого же ты такой уродился?..";
			link.l1.go = "givemepearl_yes_1";
		break;
		
		case "givemepearl_yes_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 5.0);
			SaveCurrentNpcQuestDateParam(npchar, "pearl_date");
			npchar.quest.pearlqty = sti(npchar.quest.pearlqty)+1;
			NextDiag.CurrentNode = "givemepearl_repeat";
		break;
		
		case "givemepearl_repeat":
			dialog.text = "Спасибо за бусинку, добрый дядя "+pchar.name+"!";
			link.l1 = "Да не за что...";
			link.l1.go = "exit";
			NextDiag.TempNode = "givemepearl_repeat";
		break;
		
		case "givemepearl_no":
			dialog.text = "Нет бусинки? Но как же так, дядя "+pchar.name+"?! Мне нужно ещё совсем немного бусинок... я должен их собрать. Раз так, тогда я схожу на берег. Буду искать бусинки...";
			if (CheckCharacterItem(pchar, "jewelry52"))
			{
				link.l1 = "Ну и куда же ты пойдёшь? Как ты дальше один будешь? Нет, не возьму я грех на душу. Погоди, поищу в карманах... вот! На, возьми свою белую бусинку и оставайся. Ты доволен?";
				link.l1.go = "givemepearl_yes";
			}
			link.l2 = "Твоё право, Оле. Надоело плавать со мной - можешь идти, я тебя не держу. Мы с тобой так и договаривались - пока тебе не надоест. Хотя крыс ты гонял знатно, не спорю...";
			link.l2.go = "givemepearl_no_1";
		break;
		
		case "givemepearl_no_1":
			dialog.text = "Прощайте, дядя "+pchar.name+". Оле нужны белые бусинки, иначе он никогда не вернется к маме...";
			link.l1 = "Ох, и жалко мне тебя, но что с тобой поделать? Ступай, Оле. Удачи.";
			link.l1.go = "givemepearl_exit";
		break;
		
		case "givemepearl_exit": // Оле уходит - квест не довели до конца
			DialogExit();
			RemovePassenger(Pchar, npchar);
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 5.0);
			DeleteAttribute(pchar, "GenQuest.Ole");
		break;
		
		case "mother":
			dialog.text = "Дядя "+pchar.name+"! Мне нужна ещё одна белая бусинка. Последняя... Ну пожалуйста, дай Оле белую бусинку!";
			if (CheckCharacterItem(pchar, "jewelry52"))
			{
				link.l1 = "Я знал, что ты будешь её просить. Вот, держи свою бусинку. Ты доволен?";
				link.l1.go = "mother_1";
			}
			link.l2 = "Ох, ну что же это за наказание такое... Нет у меня больше бусинок, Оле, нету!";
			link.l2.go = "givemepearl_no_1";
		break;
		
		case "mother_1":
			RemoveItems(pchar, "jewelry52", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "Спасибо, спасибо, добрый дядя "+pchar.name+"! Теперь у Оле есть все бусинки. Да, все! Теперь Оле может отнести их маме, и мама не выгонит Оле...";
			link.l1 = "Послушай, о какой маме ты всё время говоришь? И объясни наконец, зачем тебе эти жемчужины... тьфу, белые бусинки? И что значит - ты их собрал?";
			link.l1.go = "mother_2";
		break;
		
		case "mother_2":
			dialog.text = "Добрый дядя "+pchar.name+" помог собрать Оле бусинки для его мамы... Оле был маленьким, когда порвал мамино ожерелье из белых бусинок. Они все раскатились и упали в воду. Мама очень рассердилась на Оле, и Оле не может вернуться домой, пока не соберёт все потерянные бусинки\nЯ помню, сколько их было - пять раз по десять бусинок. Теперь Оле собрал их все. Дядя "+pchar.name+", отвезите меня домой, пожалуйста! Я хочу обрадовать мою маму, отдать ей её бусинки. Отвезите!";
			link.l1 = "Господи, что за чудная история... Ты ведь попал на Остров ещё ребенком. Тебя что, мать выгнала из дома за порванное жемчужное ожерелье? И ты все эти годы собирал свои бусинки? Жуть какая-то...";
			link.l1.go = "mother_3";
		break;
		
		case "mother_3":
			dialog.text = "Отвези меня к маме, добрый дядя "+pchar.name+". Я так хочу её увидеть. Она обрадуется, когда увидит бусинки.";
			link.l1 = "Я бы отвёз, но где же твой дом, ты знаешь? Где живет твоя мама?";
			link.l1.go = "mother_4";
		break;
		
		case "mother_4":
			dialog.text = "Она живет на острове, в городе, в домике с красной крышей.";
			link.l1 = "Эка хватил! Да ты знаешь, сколько тут островов, и сколько на них домиков с красными крышами? Как называется этот остров? Ну, или приметы какие, что ли...";
			link.l1.go = "mother_5";
		break;
		
		case "mother_5":
			dialog.text = "Я не знаю, как называется остров. Знаю - что остров, мама говорила папе - мы на острове! И мы жили в домике с красной крышей. Красивый домик, большой. Отвези меня к маме, дядя "+pchar.name+". Ну пожалуйста...";
			link.l1 = "Ох, ладно. Будем на каждом острове искать в городе дома с красными крышами и спрашивать твою маму. Как её зовут хоть?";
			link.l1.go = "mother_6";
		break;
		
		case "mother_6":
			dialog.text = "Маму? Ты странный, дядя "+pchar.name+". Маму зовут мамой. А у тебя маму по-другому зовут?";
			link.l1 = "О Господи, пошли мне терпение... Хорошо, Оле, мы попробуем найти твой дом. А теперь ступай на корабль.";
			link.l1.go = "mother_7";
		break;
		
		case "mother_7":
			dialog.text = "Спасибо, дяденька "+pchar.name+". Ты очень, очень добрый и хороший! Скоро Оле увидит маму!";
			link.l1 = "Ох...";
			link.l1.go = "mother_8";
		break;
		
		case "mother_8":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 5.0);
			DeleteAttribute(npchar, "pearl_date");
			// ставим Агнес Кристиансен и открываем ее дом в Мариго
			LocatorReloadEnterDisable("Marigo_town", "houseSp2", false);
			sld = GetCharacter(NPC_GenerateCharacter("Agnes", "women_18", "woman", "towngirl", 10, HOLLAND, -1, true, "quest"));
			SetFantomParamFromRank(sld, 10, true);
			sld.name = "Агнес";
			sld.lastname = "Кристиансен";
			sld.dialog.FileName = "Quest\LSC\OtherNPC.c";
			sld.dialog.currentnode = "agnes";
			//sld.greeting = "";
			LAi_SetOwnerType(sld);
			LAi_SetImmortal(sld, true);
			ChangeCharacterAddressGroup(sld, "Marigo_houseSp2", "barmen", "stay");
			LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
		break;
		
		case "home":
			dialog.text = "Мама... Мама, мамочка! Я вернулся!";
			link.l1 = "Сынок...";
			link.l1.go = "home_1";
		break;
		
		case "home_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			SetMusic("music_romantic");
			bDisableCharacterMenu = true;//лоченые интерфейсы
			locCameraRotateAroundHero(0.0, 2.0, 0.0, 0.005, 0.0, 2.0, 0.0, 1000);
			DoQuestFunctionDelay("LSC_OleReturnHome", 18.0);
		break;
		
		case "home_2":
			dialog.text = "Мамочка, я принёс тебе белые бусинки! Я собрал их все. Теперь у тебя снова будет красивое ожерелье. Ты больше не сердишься на меня?";
			link.l1 = "Господи... (плачет) Оле! Сынок, зачем? Почему ты ушёл? Да будь они неладны, эти жемчужины!";
			link.l1.go = "home_3";
		break;
		
		case "home_3":
			sld = characterFromId("Blaze");
			dialog.text = "Мамочка, возьми... вот. Я так долго их собирал. Мне помогали добрые дяденьки, особенно дядя "+sld.name+". Он взял меня на свой большой корабль, помог собрать бусинки и привёз меня домой...";
			link.l1 = "Оле... Ты так вырос, но всё равно остался ребенком... Дай я тебя обниму, сынок! Прости, прости меня пожалуйста, за то проклятое ожерелье! Больше я тебя никуда не отпущу, никогда! Мы будем жить с тобой вместе, я буду о тебе заботиться... Я искуплю свою вину, обещаю!..";
			link.l1.go = "home_4";
		break;
		
		case "home_4":
			dialog.text = "Мамочка, я так скучал по тебе... Я хочу остаться с тобой. Ты больше не сердишься? Почему ты плачешь?";
			link.l1 = "(рыдает) Нет, нет... Прости, прости меня, сынок!..";
			link.l1.go = "home_5";
		break;
		
		case "home_5": // перекидываем pchar
			DialogExit();
			LAi_SetStayType(pchar);
			SetMainCharacterIndex(GetCharacterIndex("Blaze"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Agnes");
			sld.dialog.currentnode = "agnes_11";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.2);
		break;
		
		case "final":
			dialog.text = "Дядя "+pchar.name+"! Как хорошо, что вы зашли! Спасибо, что привезли меня к моей мамочке. Мне так хорошо здесь, вместе с ней... Ведь это здорово - когда ты дома, правда, дядя "+pchar.name+"?";
			link.l1 = "Да, Оле. Это здорово. Я рад, что ты счастлив.";
			link.l1.go = "exit";
			NextDiag.TempNode = "final";
		break;
		
//----------------------------------------- специальные реакции -----------------------------------------------
		//замечание по обнаженному оружию
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("Слушай, ты бы убрал оружие. А то нервируешь немного...", "Знаешь, у нас тут не принято сабелькой размахивать. Убери оружие.", "Слушай, что ты, как д'Артаньян, бегаешь тут, шпагой машешь? Убери оружие, не к лицу это серьёзному мужчине...");
			link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажешь...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданин этого города, прошу вас не ходить у нас с обнажённым клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнажённым клинком.");
				link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "Острожней на поворотах, приятель, когда бежишь с оружием в руках. Я ведь могу и занервничать...", "Мне не нравится, когда мужчины ходят передо мной с оружием на изготовку. Это меня пугает...");
				link.l1 = RandPhraseSimple("Понял.", "Убираю.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}