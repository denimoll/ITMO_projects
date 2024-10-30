//Создаем форму: количество строк, столбцов и кнопка "создать". Кнопка убирает form1, появляет form2 и создает таблицу.
var form1 = document.createElement("form"),
    labelRows = document.createElement("label"),
    inputRows = document.createElement("input"),
    labelColumns = document.createElement("label"),
    inputColumns = document.createElement("input"),
    buttonCreateForm = document.createElement("button");

labelRows.style.display = "block";
labelRows.innerText = "Rows: ";
inputRows.style.display = "block";
inputRows.type = "text";
inputRows.id = "countRows";
labelColumns.style.display = "block";
labelColumns.innerText = "Columns: ";
inputColumns.style.display = "block";
inputColumns.type = "text";
inputColumns.id = "countColumns";
buttonCreateForm.type = "button";
buttonCreateForm.style.width = "150px";
buttonCreateForm.innerText = "Create";

buttonCreateForm.onclick = () => {
    let col = document.getElementById("countColumns").value,
        row = document.getElementById("countRows").value;
    if (col > 0 && row > 0){
        form1.style.display = "none";
        form2.style.display = "block";
        createTable(col, row);
        form1.reset();
    } else{
        alert("incorrect data");
        form1.reset();
    }
};

form1.append(labelRows, inputRows, labelColumns, inputColumns, buttonCreateForm);
document.body.appendChild(form1);



//Создаем форму с элементами. Заголовок еще
var form2 = document.createElement("form"),
    hForTable = document.createElement("h2"),
    form21 = document.createElement("form"), //изменить границы таблицы
    h21 = document.createElement("h"),
    input21 = document.createElement("input"),
    select21 = document.createElement("select"),
    button21 = document.createElement("button"),
    form22 = document.createElement("form"), //добавить заголовок
    h22 = document.createElement("h"),
    input22 = document.createElement("input"),
    button22 = document.createElement("button"),
    form23 = document.createElement("form"), // удалить строку
    h23 = document.createElement("h"),
    input23 = document.createElement("input"),
    button23 = document.createElement("button"),
    form24 = document.createElement("form"), //случайный выбор
    h24 = document.createElement("h"),
    button24 = document.createElement("button"),
    form25 = document.createElement("form"), //удалить всю таблицу
    h25 = document.createElement("h"),
    button25 = document.createElement("button");

const border = ["none", "dotted", "dashed", "solid", "double", "groove", "ridge", "inset", "outset"];
for (let i = 0; i < border.length; i++) {
    let opt = document.createElement("option");
    opt.innerText = border[i];
    select21.appendChild(opt);
    select21.onchange = function () { button21.innerText = "Change on " + input21.value + " px" + " and border " + select21.value }
}

hForTable.style.display = "block";
hForTable.innerText = "";
form21.style.display = "inline-block";
form21.style.margin = "10px";
form21.style.textAlign = "center";
h21.innerText = "Изменить границы таблицы";
h21.style.display = "block";
input21.type = "type";
input21.style.width = "200px";
input21.style.display = "block";
input21.oninput = function () { button21.innerText = "Change on " + input21.value + " px" + " and border " + select21.value }
select21.style.width = "200px";
select21.style.display = "block";
button21.innerText = "Change";
button21.type = "button";
button21.style.width = "200px";
button21.style.display = "block";

form22.style.display = "inline-block";
form22.style.margin = "10px";
form22.style.textAlign = "center";
h22.innerText = "Добавить заголовок";
h22.style.display = "block";
input22.type = "type";
input22.style.width = "200px";
input22.style.display = "block";
button22.innerText = "Add";
button22.type = "button";
button22.style.width = "200px";
button22.style.display = "block";

form23.style.display = "inline-block";
form23.style.margin = "10px";
form23.style.textAlign = "center";
h23.innerText = "Удалить строку";
h23.style.display = "block";
input23.type = "type";
input23.style.width = "200px";
input23.style.display = "block";
button23.innerText = "Delete";
button23.type = "button";
button23.style.width = "200px";
button23.style.display = "block";

form24.style.display = "inline-block";
form24.style.margin = "10px";
form24.style.textAlign = "center";
h24.innerText = "Случайный выбор";
h24.style.display = "block";
button24.innerText = "WTF?";
button24.style.width = "200px";
button24.type = "button";
button24.style.display = "block";

form25.style.display = "inline-block";
form25.style.margin = "10px";
form25.style.textAlign = "center";
h25.innerText = "Удалить всю таблицу";
h25.style.display = "block";
button25.innerText = "Delete";
button25.type = "button";
button25.style.width = "200px";
button25.style.display = "block";

form21.append(h21, input21, select21, button21);
form22.append(h22, input22, button22);
form23.append(h23, input23, button23);
form24.append(h24, button24);
form25.append(h25, button25);
form2.append(form21, form22, form23, form24, form25, hForTable);
document.body.appendChild(form2);
form2.style.display = "none";



//Функции создания таблиц
function createTable(columns, rows) {
    let table = document.createElement("table");
    table.style.borderCollapse = "collapse";

    for (let i = 0; i < rows; i++) {
        let tr = document.createElement("tr");
        for (let j = 0; j < columns; j++) {
            let td = createTableCell();
            tr.appendChild(td);
        }
        table.appendChild(tr);
    }
    document.body.appendChild(table);
}

function createTableCell() {
    let td = document.createElement("td");
    td.style.minWidth = "100px";
    td.style.height = "30px";
    td.style.border = "1px solid black";
    td.onmousemove = () => td.style.backgroundColor = "pink";
    td.onmouseout = () => td.style.backgroundColor = "white";
    td.appendChild(createTableCellContent(td));
    return td;
}

function createTableCellContent(td) {
    td.innerHTML = "";
    let form = document.createElement("form"),
        textarea = document.createElement("textarea"),
        button = document.createElement("button");
    button.innerText = "Save";
    button.type = "button";
    button.style.display = "block";
    textarea.cols = 20;
    textarea.rows = 5;
    button.onclick = () => {
        td.innerText = button.previousSibling.value;
        form.remove();};
    form.appendChild(textarea);
    form.appendChild(button);
    return form;
}


button21.onclick = () => {
    let tdList = document.querySelectorAll('td');
    tdList.forEach((td) => td.style.border = `${input21.value}px ${select21.value}`);
    form21.reset();
    button21.innerText = "Change";
};

button22.onclick = () => {
    hForTable.innerHTML = input22.value;
    form22.reset();
};

button23.onclick = () => {
    let tableRows = document.querySelectorAll('tr');
    if (input23.value < 1 || input23.value > tableRows.length || input23.value.match(/([^0-9])/g)) {
        alert('Incorrect data');
    } else {
        tableRows[input23.value - 1].remove();
    }
    form23.reset();
};

button24.onclick = () => {
    let td = chooseRandomTableDataCell();
    td.style.backgroundColor = setRandomColor();
    chooseRandomFontStyle(td);
};

function chooseRandomTableDataCell() {
    let tableRowList = document.querySelectorAll('tr');
    let tableRowIndex = randomInteger(0, tableRowList.length - 1);
    let tableDataCellIndex = randomInteger(0, tableRowList[tableRowIndex].cells.length - 1);
    return tableRowList[tableRowIndex].cells[tableDataCellIndex];
}

function setRandomColor() {
    let hexTable = "0123456789ABCDEF";
    let newColor = '#';
    for (let i = 0; i < 6; i++) {
        newColor += hexTable[randomInteger(0, hexTable.length - 1)];
    }
    return newColor;
}

function chooseRandomFontStyle(td) {
    let newColor = setRandomColor();
    let newFontSize = randomInteger(15, 25) + 'px';
    td.style.color = newColor;
    td.style.fontSize = newFontSize;
    if (typeof td.childNodes[0] !== 'undefined') {
        td.childNodes[0].childNodes.forEach((elem) => {
            elem.style.color = newColor;
            elem.style.fontSize = newFontSize;
        });
    }
}

function randomInteger(min, max) {
    let rand = min + Math.random() * (max + 1 - min);
    return Math.floor(rand);
}

button25.onclick = () => {
    document.querySelector('table').remove();
    form2.style.display = "none";
    form1.style.display = "block";
};
