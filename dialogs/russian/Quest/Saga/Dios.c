// Хосе Диос - картограф
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Вы что-то хотели?";
			if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "dios")
			{
				link.l3 = TimeGreeting()+"! Скажите, это вы - Хосе Диос, картограф?";
				link.l3.go = "island";
			}
			link.l1 = "Да нет, ничего.";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;
		
		case "island":
			dialog.text = "Да, это именно я. А вот вы, сеньор, мне не знакомы. По какому вопросу пожаловали?";
			link.l1 = "Меня зовут "+GetFullName(pchar)+" и я прибыл от Яна Свенсона. Вы помните этого человека?";
			link.l1.go = "island_1";
		break;
		
		case "island_1":
			dialog.text = "Ах, от сеньора Свенсона! Ну конечно же помню! Проходите, располагайтесь... Как дела у уважаемого Яна?";
			link.l1 = "Спасибо, дела идут неплохо. Сеньор Диос, мне нужна ваша помощь. Консультация по вопросу, в котором вы просто обязаны разбираться благодаря роду вашей деятельности. Ян рекомендовал вас как одного из знатоков географии Карибского региона.";
			link.l1.go = "island_2";
		break;
		
		case "island_2":
			dialog.text = "Я слушаю вас внимательно, сеньор. Что именно в географии архипелага вас интересует?";
			link.l1 = "На северо-запад от Гаваны, между Кубой и Мексиканским заливом, по слухам находится не то остров, не то ещё какое-то образование, не обозначенное ни на одной карте. Я хотел узнать у вас, есть ли там действительно какая-то суша, или это просто досужие домыслы?";
			link.l1.go = "island_3";
		break;
		
		case "island_3":
			dialog.text = "Хм... Вы задали один из самых волнующих меня вопросов. Указанное вами место давно уже притягивает пытливые умы географов, однако никто ещё до сих пор не отважился лично побывать в том районе.";
			link.l1 = "Это почему же?";
			link.l1.go = "island_4";
		break;
		
		case "island_4":
			dialog.text = "Всё дело в том, что это место - своего рода природная аномалия. Вероятность штормов там намного выше, нежели в любой другой точке Карибского моря. Это, возможно, связано с неким холодным течением, но я высказал лишь гипотезу. В этом районе сгинуло без вести достаточно много кораблей, чтобы отучить моряков соваться туда, тем более что основные морские маршруты проходят стороной.";
			link.l1 = "Как я понимаю, вы тоже не знаете истины...";
			link.l1.go = "island_5";
		break;
		
		case "island_5":
			dialog.text = "Именно так, сеньор. Однако я располагаю некоторыми историческими справками и вещественными доказательствами, что какое-то образование, подобное суше, имеет вероятность существования в этом квадрате.";
			link.l1 = "Вы можете мне привести свои доводы?";
			link.l1.go = "island_6";
		break;
		
		case "island_6":
			dialog.text = "Конечно. Основное - это исторический документ, в котором приводятся выдержки из судового журнала капитана Альворадо, который в 1620 году посетил это место. Презанятная история, скажу я вам!";
			link.l1 = "Капитан Альворадо? Вы уже второй, кто называет эту фамилию при упоминании о загадочном острове...";
			link.l1.go = "island_7";
		break;
		
		case "island_7":
			dialog.text = "В этом нет ничего удивительного. История капитана Альворадо попала в народные массы и за долгие годы претерпела изрядные изменения, наполнившись слухами, домыслами и мечтами, в результате чего и появилась легенда об Острове Справедливости\nНо бумага и чернила не терпят измышлений - они остаются неизменными, спустя десятилетия и столетия. Вот, прочтите эту историю - возможно, она прольёт хоть какой-то свет на то, что вы ищете.";
			link.l1 = "Спасибо! А ещё какие-либо доказательства у вас есть?";
			link.l1.go = "island_8";
		break;
		
		case "island_8":
			dialog.text = "Существует гипотеза, что в этом районе дно поднимается почти до поверхности моря, образуя обширное мелководье. Про течение я вам уже говорил. По рассказам моряков, в этом квадрате наблюдается повышенное скопление чаек и прочих морских птиц\nВ заметках капитана Альворадо упоминаются названия кораблей, которые входили в эскадру адмирала Франциско де Бетанкура, бесследно исчезнувшую при загадочных обстоятельствах более полувека назад - навряд ли случайное совпадение...";
			link.l1 = "Вернусь на корабль и тщательнейшим образом изучу записи этого капитана Альворадо. Спасибо за помощь, сеньор Диос!";
			link.l1.go = "island_9";
		break;
		
		case "island_9":
			dialog.text = "Не за что. Я ведь по сути ничем вам не помог - вы не знаете координат этого места, и я их не знаю, и достоверных фактов существования обитаемой земли в том квадрате у меня тоже нет. Но, как я понял, вы серьёзно намерены исследовать тот район?\nЕсли это так, то имейте в виду, что за любую информацию, в особенности подкрепленную материальными доказательствами, я вам буду очень признателен. Судя по всему, вы человек не бедный, но у меня будет, чем отплатить вам за предоставленные сведения.";
			link.l1 = "Хорошо. Считайте, что мы с вами договорились, сеньор Диос. Возможно, потом мои заметки тоже кто-нибудь будет читать, или даже сложит какую-нибудь легенду...";
			link.l1.go = "island_10";
		break;
		
		case "island_10":
			dialog.text = "А почему бы и нет? Да, сеньор "+pchar.name+", поскольку вы, как я вижу, человек деятельный и много путешествуете, то я хотел бы вас попросить ещё кое о чём.";
			link.l1 = "Да? Слушаю вас.";
			link.l1.go = "island_11";
		break;
		
		case "island_11":
			dialog.text = "Как вам известно, я - картограф. Так вот, я два года рисовал карты Карибского архипелага и прилегающих участков суши, составляя адмиральский атлас на конкурс вице-короля Новой Гранады. Однако все эти карты, все двадцать четыре штуки, были наглым образом украдены из моего дома в то время, когда я был похищен пиратами, из плена которых меня освободил сеньор Свенсон\nЯ уверен, что нападение пиратов было организовано моими конкурентами с одной целью: выкрасть мои карты. С того момента прошло немало времени, но я так и не встретил нигде ни одной из своих карт.";
			link.l1 = "Я догадываюсь, о чём пойдёт речь. Вы хотите, чтобы я вернул вам ваши карты.";
			link.l1.go = "island_12";
		break;
		
		case "island_12":
			dialog.text = "Именно так. Возможно, в ваших странствиях вы их повстречаете. Узнать их легко - на них стоит моя подпись: Хосе Диос. Если вам удастся совершить чудо и найти все двадцать четыре карты - я достойно отблагодарю вас.";
			link.l1 = "Хорошо. Буду внимательнее присматриваться к картам, имеющим хождение на архипелаге. Ну а теперь мне пора. Спасибо за интересную беседу и за документ!";
			link.l1.go = "island_13";
		break;
		
		case "island_13":
			DialogExit();
			AddQuestRecordInfo("LSC_Alvorado", "1");
			AddQuestRecord("SharkHunt", "4");
			pchar.questTemp.Saga.SharkHunt = "LSC";
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 50);//везение
			pchar.questTemp.AdmiralMap = "true";
		break;
		
		case "Dios":
			dialog.text = "А-а, это вы, сеньор "+GetFullName(pchar)+"? Расскажете что-нибудь интересное?";
			if (CheckAttribute(pchar, "questTemp.AdmiralMap") && CountAdmiralMapFromCharacter() > 0 && CountAdmiralMapFromCharacter() < 24 && !CheckAttribute(npchar, "quest.mapinfo"))
			{
				link.l3 = TimeGreeting()+"! Сеньор Диос, посмотрите пожалуйста, какую карту мне удалось найти. Судя по имени на обороте, это одна из ваших украденных карт.";
				link.l3.go = "map_info";
			}
			if (CheckAttribute(pchar, "questTemp.AdmiralMap") && CountAdmiralMapFromCharacter() > 23)
			{
				link.l3 = TimeGreeting()+"! Сеньор Диос, я хочу вас обрадовать. Мне удалось собрать полный комплект ваших уникальных карт, как вы того хотели. Вот они, все двадцать четыре штуки.";
				link.l3.go = "amap";
			}
			if (CheckAttribute(pchar, "questTemp.LSC.Dios")) // был в LSC
			{
				link.l4 = TimeGreeting()+"! Да, расскажу. Я был в том самом таинственном месте, о котором мы с вами говорили.";
				link.l4.go = "LSC";
			}
			link.l9 = "Пока ничего нет, сеньор. Просто зашёл вас проведать.";
			link.l9.go = "exit";
			NextDiag.TempNode = "Dios";
		break;
		
		case "map_info":
			dialog.text = "Покажите... (смотрит) Ну конечно же! Это одна из моих карт для адмиральского атласа! Капитан, очень прошу вас: разыщите все двадцать четыре штуки! Я понимаю, что прошу практически невозможного, но всё же... не теряю надежды.";
			link.l1 = "И правильно делаете, сеньор. Раз я сумел найти эту карту - значит, есть шанс найти и все остальные. Главное - что они остались на Карибах.";
			link.l1.go = "map_info_1";
		break;
		
		case "map_info_1":
			dialog.text = "Меня очень ободряет ваш оптимизм, сеньор капитан. Возможно, мне ещё удастся показать дону Хуану де Кордова, кто лучший картограф на архипелаге!";
			link.l1 = "Если нам повезёт, вы утрёте нос всем вашим конкурентам-недоброжелателям. Карты действительно великолепные... До встречи, сеньор!";
			link.l1.go = "exit";
			npchar.quest.mapinfo = "true";
			NextDiag.TempNode = "Dios";
		break;
		
		case "amap":
			dialog.text = "Не верю собственным ушам! Вы действительно нашли их? Все двадцать четыре карты?";
			link.l1 = "Да. Это было нелегко, но удача всё же улыбнулась мне в этом предприятии. Возьмите ваши карты. Они настолько великолепны, что мне искренне жаль с ними расставаться.";
			link.l1.go = "amap_1";
		break;
		
		case "amap_1":
			for(i=1; i<=24; i++)
			{
				sTemp = IdentifyAdmiralMapLast();
				if (sTemp != "") RemoveItems(pchar, sTemp, 1);
			}
			Log_Info("Вы отдали комплект адмиральских карт");
			PlaySound("interface\important_item.wav");
			dialog.text = "Поразительно! Просто поразительно! Я по правде говоря, не верил, что это когда-нибудь произойдёт.";
			link.l1 = "Dum spiro, spero, сеньор Диос. Теперь вы можете отправляться к дону Кордове. Уверен, он по достоинству оценит ваше мастерство.";
			link.l1.go = "amap_2";
		break;
		
		case "amap_2":
			dialog.text = "Огромное вам спасибо, капитан! Вы даже не представляете, какую огромную услугу оказали мне. Как я и обещал - я в долгу не останусь. У меня тоже есть для вас подарок. Думаю, что вам, военному моряку, этот прибор очень пригодится.";
			link.l1 = "Вы меня заинтриговали, сеньор!";
			link.l1.go = "amap_3";
		break;
		
		case "amap_3":
			GiveItem2Character(pchar, "spyglass5"); 
			Log_Info("Вы получили корабельный телескоп");
			PlaySound("interface\important_item.wav");
			dialog.text = "Вот! Это корабельный телескоп, моей собственной конструкции. Второго такого не найдёте нигде. Линзы изготовлены в Европе, вероятно, лучшим мастером Испании. Корпус сделал мой знакомый оружейник. Специальная подставка поможет точно навести прибор на цель при любой качке. В этот телескоп вы сможете рассмотреть абсолютно всё, что только можно увидеть на палубе корабля или в бастионе форта.";
			link.l1 = "Вот это подарок так подарок! Спасибо, сеньор Диос.";
			link.l1.go = "amap_4";
		break;
		
		case "amap_4":
			dialog.text = "Пользуйтесь на здоровье, сеньор капитан. Надеюсь, мой телескоп не раз сослужит вам добрую службу.";
			link.l1 = "Не сомневаюсь! Мне уже не терпится установить его на палубе моего корабля и оглядеть окрестности.";
			link.l1.go = "amap_5";
		break;
		
		case "amap_5":
			dialog.text = "Вы будете приятно удивлены, смею вас заверить... и ещё раз огромное спасибо за мои спасённые карты!";
			link.l1 = "И вам спасибо, сеньор. Думаю, мы с вами ещё увидимся. А пока - до свидания, пойду, опробую ваш великолепный прибор. Всего доброго!";
			link.l1.go = "amap_6";
		break;
		
		case "amap_6":
			DialogExit();
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 1000);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 1000); // харизма
			AddCharacterExpToSkill(pchar, "Sneak", 300);//скрытность (раз телескоп дали)
			ChangeCharacterComplexReputation(pchar, "nobility", 10);// репутация-известность
			ChangeCharacterComplexReputation(pchar, "authority", 5);// репутация-авторитет
			ChangeCharacterNationReputation(pchar, SPAIN, 20);
			ChangeOfficersLoyality("good_all", 5);
			DeleteAttribute(pchar, "questTemp.AdmiralMap");
		break;
		
		case "LSC":
			dialog.text = "Да что вы такое говорите! Вам удалось его отыскать? Располагайтесь, капитан, поудобнее, как я понимаю - разговор будет долгим?";
			link.l1 = "Мне действительно есть что поведать об этом острове. Но сначала я хочу, чтобы вы мне пообещали кое-что. Как я вижу, вы человек честный и порядочный, посему я уверен, что вы сдержите слово...";
			link.l1.go = "LSC_1";
		break;
		
		case "LSC_1":
			dialog.text = "О чём вы сейчас, капитан?";
			link.l1 = "На этом острове живут люди... которые, как я понимаю, не очень желают вмешательства в их жизнь посторонних лиц. Не думаю, что там будут рады прибытию эскадры 'исследователей'. Поэтому я прошу вас дать мне слово, что в течение десяти лет после нашего разговора вы не опубликуете ни одного точного факта или детали, благодаря которым Остров может быть найден. Всё остальное - устройство, быт островитян и прочее - пожалуйста, но по возможности так, чтобы это не обернулось бедой для тамошних обитателей.";
			link.l1.go = "LSC_2";
		break;
		
		case "LSC_2":
			dialog.text = "Я согласен, капитан. Даю слово дворянина, что никто от меня не узнает ни о точном местоположении острова - в течение десяти лет, ни сведений, которые смогут так или иначе навредить его жителям - никогда.";
			link.l1 = "Тогда слушайте мой рассказ. Или даже - запишите. Итак, Остров этот состоит из большого числа погибших в разные эпохи кораблей, чьи остовы разместились на обширном мелководье...";
			link.l1.go = "LSC_3";
		break;
		
		case "LSC_3":
			DialogExit();
			SetLaunchFrameFormParam("Прошло два часа...", "LSC_FinalDiosStory", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 2, 10); //крутим время
			RecalculateJumpTable();
		break;
		
		case "LSC_4":
			dialog.text = "Просто изумительно! Вы рассказали очень, очень ценные сведения, капитан! Подумать только - потомки адмирала де Бетанкура живут на Острове! И теперь нам точно известна судьба его эскадры. А на карте Карибского архипелага одним белым пятном стало меньше... Огромное спасибо за рассказ, "+pchar.name+"!";
			link.l1 = "Теперь вы понимаете, почему я вас просил быть... предельно осторожным в пересказе моих сведений?";
			link.l1.go = "LSC_5";
		break;
		
		case "LSC_5":
			dialog.text = "Понимаю. И будьте уверены - слово своё сдержу. Скажите, а каких-то вещественных... атрибутов с этого Острова вы не привезли?";
			if (CheckCharacterItem(pchar, "LSC_navigation_map"))
			{
				link.l1 = "У меня есть лоция Острова Справедливости. Вот, посмотрите. Руководствуясь ей, можно провести небольшой корабль сквозь гиблые места и произвести высадку на Остров. Без неё подойти к Острову практически невозможно.";
				link.l1.go = "LSC_6";
			}
			else
			{
				link.l1 = "К сожалению, ничего такого у меня нет.";
				link.l1.go = "LSC_7_1";
			}
		break;
		
		case "LSC_6":
			Log_Info("Вы отдали лоцию Острова Справедливости");
			PlaySound("interface\important_item.wav");
			dialog.text = "(смотрит) Какой великолепный документ! Его рисовал человек, весьма искушённый в картографии. Даже я навряд ли смог бы выполнить лучше. Изумительно! Капитан, вы не отдадите мне эту лоцию? Рассказ рассказом, а вот эта бумага должна быть представлена взору известнейших географов Старого Света!";
			link.l1 = "Конечно. Для этого я вам её и принёс.";
			link.l1.go = "LSC_10";
			link.l2 = "Сеньор Диос, к сожалению, эта лоция нужна мне самому. Как я уже говорил, без неё невозможно пройти сквозь рифы, окружающие Остров. Я бы пожертвовал её во благо науки, но... уверен, вы понимаете.";
			link.l2.go = "LSC_7";
		break;
		
		case "LSC_7":
			Log_Info("Вы получили лоцию Острова Справедливости");
			PlaySound("interface\important_item.wav");
			dialog.text = "Безусловно. Это ваше право, хотя и очень жаль... Но в любом случае - огромное спасибо за ваш рассказ! Вы оказали неоценимую услугу географам, картографам и просто любознательным людям.";
			link.l1 = "Не за что, сеньор. Ну, а теперь позвольте откланяться. Мне пора отправляться в путь.";
			link.l1.go = "LSC_8";
		break;
		
		case "LSC_7_1":
			dialog.text = "Очень жаль... Но в любом случае - огромное спасибо за ваш рассказ! Вы оказали неоценимую услугу географам, картографам и просто любознательным людям.";
			link.l1 = "Не за что, сеньор. Ну, а теперь позвольте откланяться. Мне пора отправляться в путь.";
			link.l1.go = "LSC_8";
		break;
		
		case "LSC_8":
			dialog.text = "Конечно, "+pchar.name+". Вы и так уделили мне столько своего драгоценного времени. Передавайте привет сеньору Свенсону!";
			link.l1 = "До свидания, сеньор Диос.";
			link.l1.go = "LSC_9";
		break;
		
		case "LSC_9":
			DialogExit();
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 400);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 500); // харизма
			ChangeCharacterComplexReputation(pchar, "nobility", 5);// репутация-известность
			ChangeCharacterComplexReputation(pchar, "authority", 2);// репутация-авторитет
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			ChangeCharacterNationReputation(pchar, SPAIN, 5);
			DeleteAttribute(pchar, "questTemp.LSC.Dios");
			LAi_SetOwnerType(npchar);
		break;
		
		case "LSC_10":
			RemoveItems(pchar, "LSC_navigation_map", 1);
			dialog.text = "Огромное спасибо! Это очень любезно с вашей стороны. Теперь мы располагаем не только устными, но и вещественными доказательствами... Я тоже в долгу не останусь, капитан. У меня есть для вас небольшой презент.";
			link.l1 = "И какой же, позвольте полюбопытствовать?";
			link.l1.go = "LSC_11";
		break;
		
		case "LSC_11":
			sld = characterFromId("Pirates_shipyarder");
			sld.quest.sextant = "true"; // атрибут Алексу на хронометр
			GiveItem2Character(pchar, "sextant1"); 
			PlaySound("interface\important_item.wav");
			dialog.text = "Я увлекаюсь не только географией и картографией, но также и астрономией и математикой. Я целый год пытался создать универсальный прибор для определения географической широты и долготы. И кое-что у меня получилось. Вот, взгляните\nЭто мой секстант. Я сам сделал его. Но вот в чём беда: он не работает. Для него нужен очень точный хронометр. Все, что попадались мне в руки, даже изготовленные лучшими мастерами, дают недопустимо большие погрешности. В итоге мой прибор оказался не востребованным\nВы много путешествуете, и возможно, вам удастся отыскать где-нибудь такой хронометр, с которым секстант сможет работать. Если вы найдёте такие часы - то вам больше не нужно будет возиться с буссолью, компасом, астролябией, песочными часами и дрянными хронометрами - мой прибор заменит вам всё это.";
			link.l1 = "Спасибо, сеньор Диос. Будем надеяться, что я отыщу хронометр, который заставит ваше замечательное изобретение функционировать. Было бы очень хорошо иметь такой прибор... в работающем виде. Ну, а теперь позвольте откланяться. Мне пора отправляться в путь.";
			link.l1.go = "LSC_8";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}