var targetInput = document.getElementsByClassName("radioInput")[1].getElementsByTagName("input")[0];
var enrolBtn = document.getElementById("enrol");
// var currentCourseTable = document.getElementById("LEC-0101");
var currentTable = angular.element(document.getElementById("LEC-0101")).scope();
function init(){
	currentTable.info.readOnlyMode = false;
	currentTable.primaryActivityIndex = 0;
	currentTable.full = false;
	currentTable.checkedStatus = true;
};
init();
//var enrolBtn = document.getElementById("enrol");
setInterval(function () {
	targetInput.click();
	//currentTable.click();
	enrolBtn.click();
}, 1500);
