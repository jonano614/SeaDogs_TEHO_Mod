// Дональд Гринспи - лидер нарвалов
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Ну? Чего тебе надо?";
				link.l1 = TimeGreeting()+". Меня зовут "+GetFullName(pchar)+". Вот, зашёл познакомиться с главой клана на Острове.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "А, "+GetFullName(pchar)+"! Ты что-то хотел?";
				link.l5 = "Да просто решил узнать как у тебя дела. Ещё увидимся!";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // первая встреча
			dialog.text = "Ну вот и познакомился. Моё имя - Дональд Гринспи, и берегись, если ты разозлишь меня или моих людей. И не суйся на 'Сан-Габриэль', если, конечно, тебе не дадут пароль - это плохо для тебя кончится. В магазин ходи, сколько вздумается - торговать-то надо всем. Ещё вопросы есть?";
			link.l2 = "Больше ничего, информация исчерпывающая. До свидания!";
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
	// ----------------------------------после разгрома Чада и Мэри на Каролине---------------------------
		case "shark":
			dialog.text = "По какому вопросу пожаловал?";
			link.l1 = "По достаточно неприятному, Дональд. Минувшей ночью на Стивена Додсона было совершено покушение. Причём бойцы твоего клана приняли в этом самое деятельное участие.";
			link.l1.go = "shark_1";
		break;
		
		case "shark_1":
			dialog.text = "Ничего не знаю об этом. С чего ты взял, что это дело рук моих бойцов?";
			link.l1 = "Да потому что я присутствовал при этом. А уж отличить твоих людей от людей Акулы, и уж тем более ривадос, мы в состоянии. Возглавляли шайку нападавших ваша Мэри Каспер и предатель Чад Каппер. Какие ещё доказательства тебе нужны?";
			link.l1.go = "shark_2";
		break;
		
		case "shark_2":
			dialog.text = "Могу тебя лишь заверить в том, что я лично и мои люди не имеют к этому никакого отношения.";
			link.l1 = "Тебе придётся заверить в этом адмирала, а сделать это будет ох как непросто. После этого нападения, в результате которого Додсон чуть не распрощался с жизнью, он весьма зол на всех нарвалов без исключения. Акула собирается объявить вам войну - прекратить отпускать продовольствие, и отстреливать твоих людей при каждом удобном случае. И это не пустые слова.";
			link.l1.go = "shark_3";
		break;
		
		case "shark_3":
			dialog.text = "Надеюсь, адмирал отдаёт себе отчет? Или он сомневается в том, что мои люди тоже умеют стрелять?";
			link.l1 = "Думаю, что отдаёт. Он готов превратить 'Сан-Августин' в крепость и выдерживать осаду до тех пор, пока вы не перемрёте с голода. Кроме того, Додсон готовится отправить посла к Чёрному Эдди с предложением о сотрудничестве - если против вас пойдёт и адмирал, и ривадос - вам не устоять.";
			link.l1.go = "shark_4";
		break;
		
		case "shark_4":
			dialog.text = "Чёрт побери! Но мы же действительно не причастны к этому покушению! Если эта дурёха Красная Мэри, ослеплённая жаждой мести, и несколько отморозков из моей команды напали на адмирала - то причём здесь весь клан целиком?\nК тому же, давай рассуждать здраво: убив Алана Милроу в тюрьме, Додсон сам спровоцировал и Мэри, и моих бойцов. Когда делаешь подлость, то следует быть готовым к тому, что за неё придётся заплатить.";
			link.l1 = "Ничего ты не знаешь и не понимаешь. Вас обвели вокруг пальца. Откуда у тебя такая уверенность, что это Додсон прикончил Алана? Он, например, считает, что это ты его шлёпнул, чтобы занять место лидера...";
			link.l1.go = "shark_5";
		break;
		
		case "shark_5":
			dialog.text = "Мне всё равно, что он считает. Против адмирала были все улики: никто кроме него и его людей не мог войти в тюрьму. Алан был целиком и полностью в его власти. Красная Мэри, которая плавала тайком на 'Тартарус', много чего рассказывала. Перед тем, как Милроу убили, Додсон лично посетил тюрьму, что делает крайне редко.";
			link.l1 = "Ты сам видел, как Акула убивает Алана? Нет?";
			link.l1.go = "shark_6";
		break;
		
		case "shark_6":
			dialog.text = "Что за вздор! Нет, конечно.";
			link.l1 = "А вот Чимисет видел убийцу Алана. Да-да, колдун ривадос, который сидел в клетке рядом с Аланом, и которого тоже недавно зарубили в тюрьме. Я был там за день до его смерти и разговаривал с ним. Милроу был убит Чадом Каппером, боцманом Акулы.";
			link.l1.go = "shark_7";
		break;
		
		case "shark_7":
			dialog.text = "Это правда?";
			link.l1 = "Сам подумай: Чимисету наплевать на ваши отношения с адмиралом и ваши внутриклановые разборки. Ему не было смысла лгать. Старый негр панически боялся Каппера, так как полагал, что будет следующим. И, как видно, не ошибся, к сожалению - Чад разделался с ним, как только узнал, что адмирал собирается его выпустить.";
			link.l1.go = "shark_8";
		break;
		
		case "shark_8":
			dialog.text = "Но зачем Капперу нужно было убивать Алана?";
			link.l1 = "Чёрт возьми, неужели не догадываешься? Я же сказал, что Каппер вместе с Красной Мэри руководил нападением. Он решил занять место Акулы и разработал для этого хитрый план. Убив Алана Милроу и распространив слухи, что это сделал Акула, он настроил против адмирала клан нарвал...";
			link.l1.go = "shark_9";
		break;
		
		case "shark_9":
			dialog.text = "";
			link.l1 = "Глупая девчонка, Мэри, поверила ему, и, пылая жаждой мести за смерть дружка, встала на сторону настоящего убийцы. Вдвоём они подговорили нескольких нарвалов - думаю, Мэри это труда не составило - и организовали нападение в каюте Фацио, которого угрозами заставили написать предательское послание адмиралу...";
			link.l1.go = "shark_10";
		break;
		
		case "shark_10":
			dialog.text = "";
			link.l1 = "У меня на руках письмо Фацио, в котором он раскрывает всю суть этого гнусного плана. Чимисета Чад убрал, как опасного свидетеля. А действовал он сообща с нарвалами, так что ривадос весьма обрадуются этому факту, когда Акула будет вести переговоры о создании коалиции. Мы легко докажем Чёрному Эдди, что Чад переметнулся к вам - достаточно будет показать письмо Фацио.";
			link.l1.go = "shark_11";
		break;
		
		case "shark_11":
			dialog.text = "Хм. Ну раз все козыри у вас на руках, тогда скажи, зачем ты сюда явился? Ты ведь сделал это не просто так - тебе что-то от меня нужно?";
			link.l1 = "Нужно. Потому что в отличие от Акулы я считаю, что всё это затеял Чад. Он обманул Мэри, та позвала на помощь знакомых из твоего клана - вот так всё и вышло. Во всяком случае, мне не удалось отыскать следов причастности к этом делу тебя или кого-либо другого из нарвалов...";
			link.l1.go = "shark_12";
		break;
		
		case "shark_12":
			dialog.text = "";
			link.l1 = "Но то, что мне не удалось найти - не значит, что заговорщиков больше нет. Я хочу, чтобы ты разыскал среди своих людей тех, кто имел отношение к нападению на адмирала. Тогда, возможно, мы сможем уладить этот конфликт, не доводя его до кровавой бойни.";
			link.l1.go = "shark_13";
		break;
		
		case "shark_13":
			dialog.text = "Я тебе уже сказал - никто из моих людей более не участвовал в этом. Мэри после убийства Алана совершенно отдалилась от клана, запершись у себя в каюте. Я вообще не представляю, как ей удалось кого-то уговорить подписаться на это дело, но видимо - удалось. Я клянусь тебе, что ни я, ни кто-либо другой из клана нарвал не замышляет ничего против адмирала\nИ так было слишком много жертв в последнее время, чтобы продолжать кровавые разборки. Я не боюсь нападения адмирала, даже вместе с ривадос: нарвалы - настоящие бойцы, и мы докажем это, пусть даже в последнем для нас бою. Но в чём смысл этого?\nМы же решили сосуществовать с адмиралом мирно. Ривадос - это другой вопрос, с неграми мы не договариваемся. Я готов лично принести извинения адмиралу и за нападение, и за подозрение в убийстве Алана, и поклясться на Библии в искренности своих слов. Вас с Додсоном такой вариант устроит?";
			link.l1 = "Хорошо. Ты уверен, что со стороны твоих людей более не стоит ожидать подвоха?";
			link.l1.go = "shark_14";
		break;
		
		case "shark_14":
			dialog.text = "Полностью и абсолютно. Я немедленно поставлю в известность весь свой клан о том, кто был истинным убийцей Алана Милроу. После этого отношение моих людей к адмиралу в корне переменится, уверяю. Скажи, и стоит после этого устраивать побоище?";
			link.l1 = "Нет, не стоит. Я пришёл сюда для того, чтобы его предотвратить. Я поверю тебе, Дональд, и попробую уговорить Акулу не развязывать военных действий. У меня есть несколько весомых аргументов... До встречи!";
			link.l1.go = "shark_15";
		break;
		
		case "shark_15":
			DialogExit();
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "narval"; // ноду Акуле
			AddQuestRecord("SharkHunt", "26");
			NextDiag.CurrentNode = "narval_wait";
		break;
		
		case "narval_wait":
			dialog.text = "Ты уже поговорил с адмиралом? Какие результаты?";
			link.l1 = "Вопрос ещё окончательно не решён. Я приду позже...";
			link.l1.go = "exit";
			NextDiag.TempNode = "narval_wait";
		break;
		
		case "shark_16":
			dialog.text = "Ты уже поговорил с адмиралом? Какие результаты?";
			link.l1 = "Да, поговорил. Вопрос с причастностью клана нарвал к покушению снят, твои извинения приняты. Более того, Акула предлагает тебе явиться к нему с визитом для обсуждения условий создания мирного соглашения между пиратами и нарвалами.";
			link.l1.go = "shark_17";
		break;
		
		case "shark_17":
			dialog.text = "Сказать по чести, не ожидал... Это очень хорошая новость. Возможно, мы сможем договориться о пересмотре цен на продовольствие для нашего клана и проведении политики в отношении ривадос.";
			link.l1 = "Это уже обсуждайте вместе с адмиралом.";
			link.l1.go = "shark_18";
		break;
		
		case "shark_18":
			dialog.text = "Да, конечно. Ты оказал неоценимую услугу клану нарвал, предотвратив бессмысленное кровопролитие, а, возможно, и тотальное истребление моих людей. В знак признательности я дарю тебе этот башенный мушкетон - такого оружия ты нигде более не найдёшь\nКроме того, ты можешь беспрепятственно посещать нашу закрытую территорию, как любой член клана.";
			link.l1 = "Спасибо! И то, и другое мне очень пригодится. А теперь позволь откланяться - у меня ещё очень много дел.";
			link.l1.go = "shark_19";
		break;
		
		case "shark_19":
			GiveItem2Character(pchar, "mushket6"); 
			Log_Info("Вы получили башенный мушкетон");
			PlaySound("interface\important_item.wav");
			dialog.text = "Удачи. Если у тебя появятся какие-то вопросы - я всегда рад тебя видеть в моей резиденции.";
			link.l1 = "Я приму это к сведению. Всего доброго!";
			link.l1.go = "exit";
			CloseQuestHeader("SharkHunt");
			pchar.questTemp.LSC.nrv_friend = "true"; //флаг на проход по кораблям нарвалов
			NextDiag.TempNode = "grinspy_wait";
			AddSimpleRumourCityTip("Ходят слухи, что вы подружились с лидером нарвалов, Дональдом Гринспи. Ну, зато теперь к ривадос вам путь заказан...", "LostShipsCity", 5, 2, "LSC", "");
			AddSimpleRumourCityTip("Говорят, вы вступили в клан нарвал. Или вы всё-таки служите у адмирала? Никак не пойму...", "LostShipsCity", 5, 2, "LSC", "");
			AddSimpleRumourCityTip("Слыхал я, что вы помирили адмирала и нарвалов. Хм, а ривадос из-за этого просто в ярости...", "LostShipsCity", 5, 2, "LSC", "");
			AddSimpleRumourCityTip("Так это Чад Каппер был убийцей Алана Милроу! Вот уж неожиданная новость!", "LostShipsCity", 5, 2, "LSC", "");
		break;
		
		case "grinspy_wait": // стал другом
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "Хо! "+GetFullName(pchar)+"! Ты же... нет, не может быть! Ты жив?!";
				link.l1 = "Слухи о моей смерти были слегка преувеличены, Дональд. Ха-ха, рад тебя видеть!";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			dialog.text = "А-а, мой друг "+GetFullName(pchar)+"! По какому делу пожаловал?";
			link.l1 = "Никаких проблем, слава Богу, нет. Просто зашёл поздороваться.";
			link.l1.go = "exit";
			NextDiag.TempNode = "grinspy_wait";
		break;
		
		case "negotiations":
			dialog.text = "По какому вопросу пожаловал?";
			link.l1 = "По достаточно неприятному, Дональд. На Стивена Додсона было совершено покушение. Причем бойцы твоего клана приняли в этом самое деятельное участие.";
			link.l1.go = "negotiations_1";
		break;
		
		case "negotiations_1":
			dialog.text = "Ничего не знаю об этом. С чего ты взял, что это дело рук моих бойцов?";
			link.l1 = "Да потому что я лично прикончил несколько негодяев из твоего клана вместе с Чадом Каппером, боцманом адмирала, который и заварил всю эту кашу. Но в одиночку он бы ничего не смог сделать - твои люди активно помогали ему. Адмирал знает это и очень, очень зол.";
			link.l1.go = "negotiations_2";
		break;
		
		case "negotiations_2":
			dialog.text = "Мои люди? А кто именно, ты можешь назвать?";
			link.l1 = "Они не представлялись. Они просто доставали пистолеты и стреляли. И вообще, что за беспредельщики у тебя в клане? Готовы убивать даже своих! Ладно - адмирал, или я, но это же каким надо быть негодяем, чтобы напасть на девушку!";
			link.l1.go = "negotiations_3";
		break;
		
		case "negotiations_3":
			dialog.text = "Хм. Ты это сейчас о чём?";
			if (pchar.questTemp.LSC.Mary == "alive")
			{
				link.l1 = "О чём? Я сейчас о нападении на Красную Мэри, которое совершили два нарвала. Я совершенно случайно оказался в её каюте в критический момент. Если бы я не вмешался - они бы убили её. Имён я у них не спрашивал, не было времени, уж извини, но Мэри сказала, что это нарвалы.";
				link.l1.go = "negotiations_4";
			}
			else
			{
				link.l1 = "О чём? Я сейчас о нападении на Красную Мэри, которое совершили два нарвала."
				link.l1.go = "negotiations_6";
			}
		break;
		
		case "negotiations_4":
			dialog.text = "Что за вздор? Почему Мэри мне об этом не рассказала?! Я бы немедленно принял меры!";
			link.l1 = "До недавнего момента она вообще боялась выйти из каюты. А с тобой она поругалась - так чего же она побежит к тебе за помощью?";
			link.l1.go = "negotiations_5";
		break;
		
		case "negotiations_5":
			dialog.text = "Да не ругался я с ней! Она захотела невозможного, мы немного повздорили и я её выставил. Но это же не значит, что я...";
			link.l1 = "Ладно, не будем об этом. В конце-концов, её проблемы уже решены. Но сам факт наличия среди твоих людей полных отморозков - налицо.";
			link.l1.go = "negotiations_7";
		break;
		
		case "negotiations_6":
			dialog.text = "Что за вздор? Мэри убили нарвалы? Но почему?";
			link.l1 = "По приказу Чада Каппера, Дональд. Она слишком много знала и не захотела помогать Чаду. И вот теперь несчастная девушка мертва!";
			link.l1.go = "negotiations_7";
		break;
		
		case "negotiations_7":
			dialog.text = "Клянусь, я не знал, что случилось с Мэри!";
			link.l1 = "Ещё бы... Но вернёмся к адмиралу. Покушение организовал Чад Каппер, и помогали ему твои люди. Додсона пытались отравить, и только чудом мне удалось предупредить тяжкие для адмирала последствия.";
			link.l1.go = "negotiations_8";
		break;
		
		case "negotiations_8":
			dialog.text = "Я никому из своих людей не давал такого приказа. Додсон знает, что я не поддерживаю политику покойного Алана и считаю, что худой мир лучше доброй ссоры.";
			link.l1 = "Тебе придётся заверить в этом адмирала, а сделать это будет ох как непросто. После этого покушения, в результате которого Додсон чуть не распрощался с жизнью, он весьма зол на всех нарвалов без исключения. Акула собирается объявить вам войну.";
			link.l1.go = "negotiations_9";
		break;
		
		case "negotiations_9":
			dialog.text = "Надеюсь, адмирал отдаёт себе отчет? Или он сомневается в том, что мои люди тоже умеют стрелять?";
			link.l1 = "Отдаёт. Он считает, что такое разбойничье гнездо, как ваш клан, нужно уничтожить, пока вы не начали убивать тайком всех подряд и без разбора. Кроме того, у нас налажены отношения с ривадос. Достаточно мне прийти к Чёрному Эдди с предложением - и у нас будет с неграми альянс. Против наших объединенных сил вам не устоять.";
			link.l1.go = "negotiations_10";
		break;
		
		case "negotiations_10":
			if (pchar.questTemp.LSC.Mary == "alive") sTemp = "Если не веришь - позови Красную Мэри и спроси у неё! Она подтвердит.";
			else sTemp = "У меня есть письмо Чада к Мэри, доказывающее это.";
			dialog.text = "Чёрт побери! Но почему за действия нескольких безмозглых тупиц должен расплачиваться весь клан? Ты не подумай, я не боюсь вас. Мы, нарвалы - бойцы, и мы докажем это, пусть даже в последнем для нас бою. Но я хочу справедливости. К тому же, адмирал сам хорош: убил Алана Милроу в тюрьме.";
			link.l1 = "Ну вот что ты за лидер, Дональд... Про Мэри ничего не знаешь, про Алана тоже. Адмирал не убивал Милроу, его убил Чад Каппер! "+sTemp+" Он сделал это для того, чтобы посеять ненависть у нарвалов к адмиралу и склонить на свою сторону.";
			link.l1.go = "negotiations_11";
		break;
		
		case "negotiations_11":
			dialog.text = "Так. Хорошо. Давай иначе построим разговор. Ты ведь не просто так сюда пришёл и всё это рассказываешь, да? Тебе что-то нужно?";
			link.l1 = "Да, нужно. Я не хочу устраивать на Острове кровавую баню. Я не хочу, чтобы гибли люди. Мне не нравится идея уничтожения нарвалов, хотя уверяю - вместе с ривадос мы в состоянии сделать это. И я, как и ты, считаю, что весь клан не должен отвечать за действия кучки мерзавцев...";
			link.l1.go = "negotiations_12";
		break;
		
		case "negotiations_12":
			dialog.text = "";
			link.l1 = "Но моего голоса недостаточно - ты должен официально заверить адмирала, что данное покушение не было санкционировано тобой лично и клан не ставит целью физическое уничтожение Додсона.";
			link.l1.go = "negotiations_13";
		break;
		
		case "negotiations_13":
			dialog.text = "Что я могу сделать? Я готов лично принести извинения адмиралу и за покушение, и за подозрение в убийстве Алана, и заверить, что нарвалы не замышляют ничего против него, и поклянусь на Библии в искренности своих слов. Вас с Додсоном такой вариант устроит?";
			link.l1 = "Меня - да. Адмирала, если ты нанесёшь ему визит на 'Сан-Августин' - наверняка тоже. Но сначала я передам ему твои слова, а затем ещё раз приду к тебе, и мы продолжим нашу беседу!";
			link.l1.go = "negotiations_14";
		break;
		
		case "negotiations_14":
			dialog.text = "Хорошо. Я буду ждать результатов.";
			link.l1 = "Я скоро вернусь...";
			link.l1.go = "negotiations_15";
		break;
		
		case "negotiations_15":
			DialogExit();
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "peace"; // ноду Акуле
			sld = characterFromId("Dexter");
			sld.dialog.currentnode = "First time"; 
			LAi_SetStayTypeNoGroup(sld);
			ChangeCharacterAddressGroup(sld, "SanAugustineResidence", "goto", "goto11");
			AddQuestRecord("SharkHunt", "56");
			NextDiag.CurrentNode = "narval_wait";
		break;
		
		case "negotiations_17":
			dialog.text = "Ты уже поговорил с адмиралом? Какие результаты?";
			link.l1 = "Да, поговорил. Если ты нанесёшь официальный визит с извинениями - то инцидент будет исчерпан.";
			link.l1.go = "negotiations_18";
		break;
		
		case "negotiations_18":
			dialog.text = "Сказать по чести, не ожидал... Это очень хорошая новость.";
			link.l1 = "Да, ты знаешь, я тоже рад этому.";
			link.l1.go = "negotiations_19";
		break;
		
		case "negotiations_19":
			dialog.text = "Ты оказал неоценимую услугу клану нарвал, предотвратив бессмысленное кровопролитие, а, возможно, и тотальное истребление моих людей. В знак признательности я дарю тебе этот башенный мушкетон - такого оружия ты нигде более не найдёшь. Кроме того, ты можешь беспрепятственно посещать нашу закрытую территорию, как любой член клана.";
			if (pchar.questTemp.LSC.Mary == "alive") 
			{
				link.l1 = "Спасибо. Очень ценная вещь. Да, Дональд, ещё: помирись с Красной Мэри. Она, конечно, горячая и вспыльчивая, но зато искренняя и не умеет лгать. Из-за ссоры с тобой она отстранилась от клана и чуть не попала в беду.";
				link.l1.go = "negotiations_20";
			}
			else
			{
				link.l1 = "Спасибо. Очень ценная вещь. И - я действительно рад, что всё закончилось миром.";
				link.l1.go = "negotiations_21";
			}
		break;
		
		case "negotiations_20":
			dialog.text = "Передай ей, что я прошу у неё прощения за то, что обидел её тогда, и за то, что два мерзавца, недостойные называться нарвалами, осмелились поднять на неё руку. Ведь вы с ней... друзья, я не ошибся?";
			link.l1 = "Нет, Дональд, не ошибся. Обязательно передам. И - я действительно рад, что всё закончилось миром.";
			link.l1.go = "negotiations_21";
		break;
		
		case "negotiations_21":
			GiveItem2Character(pchar, "mushket6"); 
			Log_Info("Вы получили башенный мушкетон");
			PlaySound("interface\important_item.wav");
			dialog.text = "Удачи. Если у тебя появятся какие-то вопросы - я всегда рад тебя видеть в моей резиденции.";
			link.l1 = "Я приму это к сведению. Всего доброго!";
			link.l1.go = "exit";
			CloseQuestHeader("SharkHunt");
			pchar.questTemp.LSC.nrv_friend = "true"; //флаг на проход по кораблям нарвалов
			NextDiag.TempNode = "grinspy_wait";
			sld = characterFromId("Mary");
			sld.quest.donald = "true";
			LocatorReloadEnterDisable("CeresSmithy", "reload3", false);
			LocatorReloadEnterDisable("CeresSmithy", "reload4", false); // открываем Церес изнутри
			// здесь почищу весь хлам, который накопился
			DeleteAttribute(pchar, "questTemp.LSC.Donald_enter"); // атрибут гардов
			DeleteAttribute(pchar, "questTemp.LSC.Florentina");
			DeleteAttribute(pchar, "questTemp.LSC.Dodson_poison");
			DeleteAttribute(pchar, "questTemp.LSC.Dodson_warning");
			DeleteAttribute(pchar, "questTemp.LSC.Whiskey_clear");
			DeleteAttribute(pchar, "questTemp.LSC.CapperDie_Aeva");
			AddSimpleRumourCityTip("Ходят слухи, что вы подружились с лидером нарвалов, Дональдом Гринспи. Не пойму я вас - друг и нарвалам, и ривадос...", "LostShipsCity", 5, 2, "LSC", "");
			AddSimpleRumourCityTip("Говорят, вы вступили в клан нарвал. Или вы всё-таки служите у адмирала? Или у ривадос? Никак не пойму...", "LostShipsCity", 5, 2, "LSC", "");
			AddSimpleRumourCityTip("Слыхал я, что вы предотвратили кровавую схватку между адмиралом и нарвалами. Вы - молодец, скажу по чести!", "LostShipsCity", 5, 2, "LSC", "");
			AddSimpleRumourCityTip("Так это Чад Каппер был убийцей Алана Милроу! Вот уж неожиданная новость!", "LostShipsCity", 5, 2, "LSC", "");
			AddSimpleRumourCityTip("Присматривайте за Красной Мэри, раз уж вам повезло быть с ней вместе - она такая отчаянная! Вечно во что-нибудь влезет...", "LostShipsCity", 20, 5, "LSC", "");
		break;
//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Что ты там копаешься, а? Да ты вор!", "Вот это да! Чуть я загляделся, а ты сразу в сундук с головой!", "По сундукам шарить вздумал?! Тебе это даром не пройдёт!");
			link.l1 = "А-ать, дьявол!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Ах, вот, значит, как?! По сундукам шарить вздумал?! Тебе это даром не пройдёт!";
			link.l1 = "Вот дура!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
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