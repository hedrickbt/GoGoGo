function getCookie(c_name)
{
    var c_value = document.cookie;
    var c_start = c_value.indexOf(" " + c_name + "=");
    if (c_start == -1)
    {
        c_start = c_value.indexOf(c_name + "=");
    }
    if (c_start == -1)
    {
        c_value = null;
    }
    else
    {
        c_start = c_value.indexOf("=", c_start) + 1;
        var c_end = c_value.indexOf(";", c_start);
        if (c_end == -1)
        {
            c_end = c_value.length;
        }
        c_value = unescape(c_value.substring(c_start,c_end));
    }
    return c_value;
}

var temp_s_accountID = getCookie("TAG_USER");
var temp_s_user_company = getCookie("TAG_USER_COMP");

var s_accountID = (temp_s_accountID == null) ? "" : temp_s_accountID;
var s_company = (temp_s_user_company == null) ? "Not Set" : temp_s_user_company;
var s_user_company = (temp_s_user_company == null) ? "Not Set" : temp_s_user_company;