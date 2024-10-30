$(document).ready(function(){
    
    
//1 задание. CSS    
    $("#first").css("color", "blue");
    $("#second").css("letter-spacing", "3px");
    $(".vk").css({
        "text-decoration": "none",
        "color": "red"
    });
    $("form *").attr("disabled", "true");   
 
    
//2 задание. DOM
    $("a").prepend("&#11016;");
    $("a").attr("target", "_blank");
    $("a").attr("href", function(index, href){
        let site = href.substring(href.indexOf(":"), href.length);
        return "https" + site;
    });
    $("#ButtonDOM").css({
        "height": "50px",
        "width": "100px",
        "position": "absolute",
        "top": "0px",
        "right": "0px"
    });
    $("#ButtonDOM").click(function(){
        $("a").removeAttr("target");
        $("a").text(function(index, href){
            return href.substring(1, href.length);
        });
    });
    
    
//3 задание. Эффекты
    $("#fadeOut").click(() => {
        $("#fadeOut").parent().siblings().children().fadeOut();
    });

    $("#fadeIn").click(() => {
        $("#fadeIn").parent().siblings().children().fadeIn();
    });

    $("#fadeTo").click(() => {
        $("#fadeTo").parent().siblings().children().fadeTo(1000, 0.2);
    });

    $("#slideDown").click(() => {
        $("#slideDown").parent().siblings().children().slideDown();
    });

    $("#slideToggle").click(() => {
        $("#slideToggle").parent().siblings().children().slideToggle();
    });
    
   
//4 задание. AJAX 
    $("#ajax_content").css({
        "border": "1px solid black",
        "height": "300px",
        "width": "300px"
    });
    $("#ajax").click(() => {
        $("#ajax_content").load("https://inxaoc.github.io/example/ajax-1.html");
    });  
    
});
