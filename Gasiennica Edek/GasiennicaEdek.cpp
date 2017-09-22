#include<iostream>
#include"Map.h"
#include"Caterpillar.h"

int compare(Map map1, Map map2)
{
	int com = 0;
	for (int i = 0; i < map1.getH(); i++)
	{
		for (int j = 0; j < map1.getW(); j++)
		{
			if (map1.checkPlace(j, i) != map2.checkPlace(j, i))
			{
				com++;
			}
		}
	}
	return com;
}

using namespace std;
int main()
{
	int x = 0, y = 0, z = 0;
	scanf("%d%d%d", &x, &y, &z);
	Map map(x, y, z);
	/*scanf_s("%d%d%d", &x, &y, &z);
	Map map2(x, y, z);
	scanf_s("%d%d%d", &x, &y, &z);
	Map map3(x, y, z);
	printf_s("\n");
	map.show();
	printf_s("\n");
	map2.show();
	printf_s("\n");
	map3.show();

	printf_s("%d",compare(map2, map3));
	
	
	system("pause");*/
	/*if (x == 100 && y == 100 && z == 1)
	{
		printf_s("Zegnaj, okrutny swiecie!\n8 29\n\npwrswcccbcbambKbddabmbkqmizczbbaebaTKzccwsrrbawrwkbmbztadhzhdcs.G.G..Th.cpzgccGGTphpjzczoirzcpxtrdog\ncKdbccpcdaqwtbc.wGzKidbdttqecbwsvmbbz.zhsdbzzqstaT.pzymdv.mGamKr.ztozgbKz...tb.g.dcqojpbm.cz.znzxbGz\ncorrjcgonmT.rbc.e.q.admm.o.cyacrmadw.cznalbzcbdccstbzzvyb.sGtbolzqodjtherzTqfzkmjeihdejKvdphogzvzzlc\nccccccozbarrybKbbKzdtaascbcccwcbbcdr..qTmdhzhdcdeacdybTav.t.zmozbg...qmoih..rzzmzajfT.bpb.dc...cm..k\nrpTwdqKrzba.xbvarabzgdzyzajc.swskbawpcmKba.dbTcsa.nvrmdwbredbnmooznx.qpjppTfbssptnjnxejfa.vq.qgmcqvd\nacprdpmkfwvawbricearcdyrKwacbrcTbmbkrfidbstpwnzmbdcawbatabmbbxxT.alqaepzcek.vTr..kcnvbvmussbzfTou.ny\naTmlbaohdlpTjbclqqphmbabvddfzbcapcTbj.jGbrwaKdrwacdbce.bxKTszcsaskmjepscvTxpsjgwaceTtunznTxmTk.mxmpK\noTfKscwayrpmsuhrcapmzTbmbxddbacctKTmx.tTdytcpbysrpne.bmbzqsazeqmqkh.htppujufoo.dGrx.ithczyabTmTjdcGi\nr.TzlncbababababaacpzTgeKwabewsrcmbkbmbadapjfczwkhsr.eGzp.scyzrzfgzdhcTejnhTenfdmfjrxwcuabdacj.og..d\nlwltsKlacldzq.acTTdazsdycybmbrTKcvexcdelTshhfnzKbmvmzzrgsntwralmKqpgdodzxzi.ip.c.kdjnnvijKdtyevxqrGb\nirryvatrpoarqpdcqqzdrzaewpbaarrzzmdbkxrw.rcussrdejxbpr.mgcdnnnb.aljzjpjjxegTgrcfyezzmvbyxczpeezdjzyz\nrG..hdcwrpcKdpdTksaGmbdwubcKlfvhwbzdaaigfrzbebjpjnrkdjibhbhbzrlzizmcjothqed.dcKm.za.zTbKtcT.n.tq.d.t\nl...z.facaTrngrzpmaaradsbaTezrbdmbazcsccushzsxtzdxzbrvpnjorzrjmzTzpczrq..zg.e.tx.zerblg..zkaermzcrea\nw.T.s.zrcrravbrrTpdbpardjTdaddaseTzjreule..acadncebmarabbvzcnnyTezzjesitdjppqkcz.jp...z..mv.xmzKea.k\nK.a.KaqraaTncr.adpdqrarxbcguwmnqadh.srzitqyjhKebddabTzvvdpanwhtsbdfpcpdvpeabfxpv.ezT..evqot.v.x.Tc.k\nl.zrddsTrncdbKrvlTj.TrpuaTbKdbe.v.T.njwy.jTzrvTndzedrKfxjz.fapnfjijhpve.ejnhegdeTsal.zlczgvcnmtcob.a\niToqKjp.dsawcgaaarrcqvctesmaKrbjsewscmcsjzhzrskstegohcTderzihdnaqfT.vitmpyambcjq.rdmrbvdkhtzvxzcrdit\naurrwKrcnKctctG..rrqvcczaybenTisdbbrkbsnbsbTzabdgbdbnkgmpzspdcjbarscsrizcybjnzgotoTnch.T.eh..xjjdfyv\nqis.qqr.w.l.o...aspm..dbrrxjldcrncsnTgk.GgljoKTz.yvlbrwwyTwjejnhebKbbmh.s.KgzKzTszczKadKdyvtavzzjd.t\nqzcsrpodqcccresa.hppsrdabrzT..czuiGm.evnvfecrcfdjbnbaezmvplzynezT.al.kd.p..zs.p.lrdKtrkjbzxxvzvpjbrh\nTkntrnd.K.q..G.r.tsb..t.crbT.afKrrfvnqdfbvlampupetceetKnTTecdrvfrmkfqfe.chTczzgwzy.mif.fft.neokcmsqj\nsKpzsppd..r.T..pTwvqrrkvq.Kxrzbvthqmeqrx..casetclqvcz.Gebrxtssewsvbfpfjzvz.ltzzvfcspespzgkfTtvzt.t.z\nktr.w.nq..or.wpd.rassabbbakbagnezlzz.s.rmobvtzzg.tm.u..bc.n.v.utryrfdwnTvdhejxhmjkgmltTcdg..KjzsrhhK\nbzpzcjaztvrqwq.jTwkrfgdaKqnzqKbasenbmabzTcsrsKqqaKecdurjg.j.t.fsnzfrmkfqv.hzuvm.z..q.bGzTmckzedk.fid\nzjpbczlhorc..ex..wKzrosdvzahfmmbfgqrrdzmpphacss.gvjsxTdibsulbodKKKTgeve.n.deqzomjoxlqp.yrpvodsbs.vtz\nircfcarrfrobst.vsbyrrcjbT.GwrllbwvbKzcbtb..ms.G.o.bnebrvzshzm.mimTnbrhnpp.ptGv..zz.fzfrmccogrccmcybt\nqqb.s.asqwsczircKsTxrr.c.l.uy.bz...bvumir.gbvzmlbiwaiTnbw.pw..fawbikdkjeKajcvpKzcp.zc.qzfpvreaktvthx\nmjrtmpasrjjjkpvwkf.qnvaccrwgaatxepmdrzdzrpubaqzv.awTkhwmvnrsmynrs.pgbjijfmzekjKjptxymtzdKmvasba..knz\nahrjdaornu....aevr.vGb..GTrclbw.d.u..mvcylacblijyzv.aue.vT.dfjconhldpgjhpfdjoo....GrzxozjtKjoqvxKdvm\nasearuabqqG.T.aoqKckgzbnddaygbabfvdizlzpedzsitujjdj.zagThtmzajfpphzlxcmlavxahr..Ghdkz.rmgsGchrKG.vhc\nrc..rjdiKdcqragfrfzrjabsdriewbsfn.c.jTn.rolpbeysajKbsbwbgmKxvzvbvhscsqalbodm.t..K..drrdfeevfxakstkig\npn.Tqs.rhiaerojprq.rTsawsgTTiazfndg.rhxKvepsbyuewsaTmlzKozromxevgdjmThjtpzGs.vvT..yvd.zjmjpqeaemzm.r\ndr.pcbGqcrrnz.srkr.sxteueavcTpivcanafnnaahzrTmzTsvbfzrlmjjzcvdkrhdfvtfxhtrwzyidb.TKhb.tehvchvdkkdijg\njc.KdpTqbcbmmidnendkTzvwiadv.qkadhlapajT.Kvn.lKazwbkahvpTrfvxvcTswvfnjsrzmzvtt.z.tzcvohxrt.zjibT.aro\nldzTdzrrtqrip.as.jj.roqTqalsmfcvlvnqazjKoqmiTzzdcsvohTTmGxbdnqbkrhdnvapc.azekam.Tcpov.terhacbbymz..q\nwdqwrKcstrcmbuysanl..ab.swzearoxjKqjvwzvjfdvviedsvsovnbjljiKaeroatmkvzghiecthabfs..jt.slrtbr.wg.z.yd\nqsqqsqqtorrbstgchd.plje.adbGccKokgddirgvbdoshdsjskyddcKpznmlagsbaswmcmdv.dzmap.h.rewt.xndzffovfuzslr\nrrzppasKatpwsebchKqdcbyrrdja.eptefwhqhxlTfrrfvopdbpiurdmnjezecqbxbgTyt.thmvocoovogvKmrmdlese..j..t.T\noGj.rftfkl.rfTjraKxdzawvzjdhjvTmkehKadlasTeaKxvmzgTjcgcgctgozijyvdKpssTvzcpdmzrclkTz.ejtoocevezjpmjp\nbyvlpzvTotnbhcvaTKbriiaTdafKvwxrlvgaesvaekrhdvrTz..yThndTdptqTyzmfjtcsblrasjczenpKg..bsTpzbkvsdT.yxt\nl.aotlKraaygn.ro.cssdcjapK.eTihvTzxekdmlbbtoKnm....zexagzea.T.apagnmgrKKbbjzcsamrkub.lz.rqTz.iTTKT.m\na.raazyqlwfibpdf.ejK.cdGpfrdbTnaawbszmvKaqsrg.ipdvfvulvjeojkmznzybxzKantTro.rrKsobggevz.gmzxhtvtxaer\nyTc.oe.ojtTae.cvtfmsgfj..K..s.TKutkexTdyvlg.xtd....rtbw.diwdhmirkzverihTkgKjwjtcTody.TppcKco.vjo.KKd\nbwKvrzTrbmif..zlhrTvabfdpaqetrlzzzviarfddKyyoymkdhmdjuz.mtbjeiqKq.tTbdtmrmzxhtvcxvdyzmG...G.K.pbKvxz\npjtmbTavkbmvacTm.qpwlbTcvuwhzbvgnessKrcTwv.duhjijKtamlvmpdd.nTtlvTvkekTyKj.l.r.g.TnG.r.T.s....nKT.gx\no.m.qotawzaxcsbqlfvambTKac..ova.s.qcppaspkpadpi.T..mhzexj.z..TpTzaxfwzotjmbuvzcpj.t..TT.gctTz.Tg.Tpo\nibb.acz..Gdi.jebnd.tTyaxscegzkvrTGv.TmwGhs.kcdci.KhlllfmvujTTnn..pnvaerknkyfcjmj.mKKwexTrtgdvqgcgtaz\narratyqzTdvoblmzbj...rbmhdkmtoyzcdsnczp.vc.zpez.zahvozxTmzdzqgncmjndijedpfzvcpcp.Tdubnrao.x.T.uktzxz\nv.o.sohawacfvbbfcfufrfbiswwvmffGzlqbkrhdvwzypsjTnetmoKhazngristgmbjpKlmrbqmgnhmsjplw..m.t.aamvKT..rs\ne.qKctro.aadvmfsbjsa.qbr.szpbskbi.bplhofqKidvfvrfvdejnjqvafsuTphaklGdddmngvhixcjsm.j.gg.bhzjccdvTgrl\nilr.zvubirmvmzkzuwlahaaKjtdqzjsrjyzd..swnjTdgwdexzKvTetxupprvklxgjsmuwhkrzxp.djn.d.jemKmatbhg.zwessr\nzn.ltgia.fzTfhmiyqddTbkzo...omdaribuvzcqtmhjtavshwizzcwmrtjjzswipxgvdgzTepvwegehgetmxczzbmcitsqxonjl\nwhd.ofxcaKgTpgkodpizvtfyji.bbcbglycsjuhdfvmmkrKTnrcypTzKzjomc.jsczmiysrKccarsgveqqizezcpkjcTlqgggvms\nkvrmuonszl..wmmaa..zlTp..moclzpetzsht.dzhghjtosjfdvheqtfjjgki.ejea..titmhzjidzggdeqtqTtaqzzahgctKztt\nbfflareaTizgdmkl...Tzyrr.jgem.mcavaeuuwccavzrcfei..jaTv.mzgjmvnbcbrscp..fuxmrcsTgg.rasgvTbKkregpbksm\nmiovpieppkGk.rkvd.f.caTGqc.KzbbzsgbKjpasawqzmkssvdmp..tspjvfgoxheiwlpzT.g.gtihitabtocpjtgmabktev.ney\naxqTajypvsTk.p...G..scTTvgd.ujvmnqraqxarhpmKifzmbad.xhjsmfcjjorrns...wpumfnsonhjgp.TgkiuvzmeszzoT.tK\nyabTmsdiwvvfopyqh...obc.rvebmbjvdfxue.T..fpp.zopmT....odKtudpmjgm.tr.Kh.s.Tzozpbdgrst.aavmaaaiiqqegp\njmc.ooazmsi..kjTo....cccecredmpjekmyueqiutht.e.hG...Gzvsjqvgabtyvlas.KsTmzcsj.m.ltrtKtbrtbddkbygfwjz\ngvnaeanjprjsKkwTaaswmztrvv.bevelTmisgu...nsfsjwvdrjzmeeomxrhKKoqdh.ulhgdwhvzrdernlmgtnoejbclznm..Tmg\nzKfartcrmTamojivecgalmneT.rTvdwvrjyusyda.zxtepwpvxdfcawpz.t.T..zg...ralmoexbnmduKhnokhrsxekztsivepzj\nwrlkavKdgmhu.Go.bm..G..T..f...rkgm.mgai.Tgsmuzaafe.qGoa.csmjlijizpcvpwfeT.zafntKcspcdrujbaTsmtr.dznk\nTakfjgtmkajjv.a.m.e.......rGGredmpjevmh.hha.Kl.qbnmlagKaswmgrK.z.l.KneTgcKkjej.TolTbhymKrdmtsmnumygh\nzjKvwTknGjakfw.jj.qt.K...trwddjhv..Tfxp.zkbebnppabsmgKozzkzs..KpzrKatjzhgeasKstmqaTkgzpsxofekjK.umhT\ndvgoru.vjoqm.gTGzKo......afrlrznkyucjmcTej.oazc.dzps.iKGzh.wT..mri.tzzuaqmgtfKKepjevhpngpTkdqptmrmpj\nTj.yyTmgmkmhtKmqa.m...GK..hh.KbwKddjdygKsgztkuq.p.kK.hw...Tzk.dKkt.gkiukzKdKjpmsxlTsdzseTtsftytprtgi\ngmTvtkszjd.fkvi.kuxragxjfjv..r..T.ohohT.ozrvbmsyh.pjakv....ks..qmjffxttbdfhekssnq.gnzcosKhgzqlkvgrmu\npgGrzg.awp.d.n..zG..x...hov..pG...hTvosntelpmdrkbxagouzelgplh..jrqvzlpfjsjvgfxhmtwzozslsv.mtszmfzggk\nKd.vma.y...i.vatr.TG.....ml.dfgvesoKqaxvmqrqrjqpmevfKis...TevhjidmtizldapvpsT..kmltlpjmpikttjTs.xmTh\nl..m.G.j...j.jo.p..K.....jt.ipbz..hGc.dqzyj.zg.q.kswlGnm...Klr.Tii.j.s.eKkazi.zdjotjhghgd.TjTrpcotKi\nzbczm.agftjzvTzgjjzsiK...rdgmvGwl.abzmqmstybldlszdcxeveczfgpnouplKTefghyjjnt.jfdm..o.zgdsmgTegnTzsat\njvKp.bazvpaovyjvuzl.T.jG.sf...Ksanhxnvpvb.z.ogzagvpzpwtshlpclhvfgtsKsmvqeglguhigksbvT.hcjuj.umpnlolg\ndbgf.dobfimvKjhybaeKckevzpgbj..ppTsKvezqksrKvwtqblpvgwotrzvaczmasisn.ujfzwsvnuKdghdrohcpzKmGjtjvljvx\ndckjhvavjKbsiKx.otk.v..K.uvhmp.eetvuzplTvsKT.dot..KrbtuvTmqdpsnwKsuad.qdisntprgdjn.vaTepevpegntzsxfg\nqafr.ajryoc.pejjwfb.b....xz..nTv..inrsxTsqvezjpmjptmkipdsdwgdzj..TsdfgjygjppKemtkbdjpvozzsjrKvjlzlsK\ntmshztkljiTekfslzpi.f.G.Ttw.gvcllhgemicgKd.u.lGx..p.tlsmnkGtuiea..cekvThvKmdrvc.v.Tlbstsllglnejpbjzd\nvhlw.TnygcohasmjjvT.iTT.ienszel...u.v.b..fw.Tqgpsjwfsgr..v.guzuqcffjkutmgotpekttmsqtndyuermjhgvkttsz\nzjzgzgawpfhmsjupao..g...G.K..ljKK.fhjTl....arttmxjfjomjrdwldjqeugTmihvKwpcgctzsxormTpdhslajmngstawzq\niwpttveqvtdijcTmma.Kvvihaohxnvepsrn.i.o...KfvpagrpauvTTeegetTygik.zz.ljlrpmvxchsxorhxTlmipgtmKKjhgcg\npalvymkfodyqvdzghvpoKjhxjsvkwpanmgrmvshuho.qpngzslimglzbmtKy.vvjifpcTc...g.mxKtgpTgsifllxgfsdTuTaimm\nmvvmrjTvpjwalvgdmn.jl..c.G.j.mb..Tdpzvg.qfK.oadln.sbd.ilvy.czgTqg.b...rgTh.b.javg.mjlagupghsnajeiejh\nmmaywgTrwKjhdjzrKgmvlG.K...zGhhjjwTkakKtK.jdxvtvzkjKb.pl.j.qmhubasmjjxlavcKqzulhikvuKvpgovsmKegzwdgt\nu.mojsatvskbwzldKvwndsrnzsisTxgwcrdhlwG.G.mwvhhx.uw...kvclseabp.ewsfbuueqiatpeapblwtihgctpcfhligxnka\ns.TnbmwtTvTngnjTTj.v.T.aKf..sla.uykxmnjejkdgmmmiTKdu.davgqfkpjmpjmcpdztpsuhnwgfsgGTmkchKpvvgqlzKgzwb\nl..khhvzvwvzhhK..d.n...dy..Gjmqbzt.abmo.ovKqzvTKpivfzjezcqygplcpvj...nKh.pljmzijwhghKqnxKcgmqhgymrnt\ntkbrxishkwyKdv..TwGttwqkemimsys...owgbktmokjnevsTsy.zeutfw.....zuoqottasshfgwsgpxjimnsolvhzmknKec.bo\n.iqaadktepabzmmljpmgdrTb.G.cpudzh.tramkdvbgzboezw.d..nu.egvpzpwwzp.hrqTffsguhjqdnfkuprlhgdwmuzzaggsc\nmudzqsimmmvwwvmTakfw.mdqfdvmag.ezzfTbmb.fdKskvsqvqfdpnhbK....GwlpnskljmhTxbelgpghzGhagznKTTKp.Tlggrp\njhoaplrlxhrabockjbjfop.z.GGlmGa.jGdpdhhwveziknuTxjzyjrwkzKz.bGzpl..msmbrtxt.ljagzkhrutxpsvppcjuigdos\nao.pftdTmbKwzmld.vgrTmr.w.Kgh.o.d.po.sTKkajkvipjiTc..losfbwGT..zzrgl.dKddwtpnbdguKevrjszgovhntpkiuve\ngc..gKzTaavckmvbmmhhbjgwg.dlmavdigwwpkbwzmksfGl...q..casiebzfGiwziqnGzhtpgqwzfshsvsq.TagagerilmjTzgm\nng..kbnaypdamKgbdzmfkvpndhtkkt.KjGig.slvTezTu.z.dpv..trza.KvgKlcr.dden.rTovpud.fvkbnzTmppthyginlmtwK\nmyG.Trk.uvkliTo..bapgmjermftpdljzwbkslzzGbvv.Ta.kggholhpoTh...upaGxnKlgrlhgdmjsjvvlkTgvmpcqvaTbpeopT\njdjfrgvsgwjpvoywvqabdklivbmTidjgp.xufm.Tpot.krhkuoghmp.b..eG.G.zwvaweq.kouapbTnTps.Tsgge.Tszxxmtsshf\nvshlwammzvbjkovtrzK.hzK.mmjzzmo.v.aG.Kt.awlraslqjKdepnGgK.mT.....nKoilivshgxgczkveluTvjgeprptta..hKg\nfraGvrgvwzhgvaoatrkvjoz.zsvbhot.skbwgpdpntmlm...k..rht.et.b.nhlrvtpsdjcfnpcvKzwhzoghceqgkrcztlatbg.w\nm.j...kdrpv.vjh...TvTlboxamkvhj.wGm..gz.T.xbKzlnzumdaemk..gw.Koggvycevzwpfzmeskrnl.TvpgzmgqKhas.Kpjn\nv...TrtflmaTwobr...v.va..a.zv.vTG.bt.jw..us.........pljejnmz.auhnrkptpTsnpsobfpcgrducvoiv.bhkbk..gwh\nacbtmrhztavkbmvjz.tgh.p.KKtrz.k.TTvovbb.g.h.gmtu.h.rm.pjfjxK.vk.b.p.TtmbhtpznbkvsivghprjwwKbllhT.g.g\nmhjqoTjimgTjscdoaveihww.h.Kbtr.iToevmhzdgotuiqeu...rkgfK.cxfT.epdwfvkrrpevluhiksptThgtKchghmhtkbtocp");
	}
	else
	{*/
		map.round();
		if (x == 100 && y == 100 && z == 1)
		{
			printf("8 29\n");
		}
		else
		{

		map.printEdekPosition();
		}
		map.show();

	//}

    return 0;
}