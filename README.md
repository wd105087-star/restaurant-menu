
<html lang="zh-TW">
<head>
    <meta charset="UTF-8">
    <title>雄中115的會沅制餐廳</title>
    
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css">
    <link href="https://fonts.googleapis.com/css2?family=Noto+Sans+TC:wght@400;500;700&display=swap" rel="stylesheet">
    <style>
        body { 
            font-family: 'Noto Sans TC', Arial, sans-serif; 
            margin: 0; 
            padding: 20px; 
            background: linear-gradient(135deg, #fff6e5 0%, #fff0db 100%);
            min-height: 100vh;
        }
        .header { 
            display: flex; 
            justify-content: space-between; 
            align-items: center;
            padding: 12px 20px;
            background: white;
            border-radius: 12px;
            box-shadow: 0 2px 12px rgba(255, 87, 34, 0.1);
            margin-bottom: 24px;
        }
        h1 { 
            margin: 0; 
            background: linear-gradient(45deg, #ff5722, #ff7043);
            -webkit-background-clip: text;
            background-clip: text;
            -webkit-text-fill-color: transparent;
            font-size: 1.8rem;
            font-weight: 700;
        }
        .cart-button { 
            position: relative; 
            padding: 10px 18px;
            background: linear-gradient(45deg, #ff5722, #ff7043);
            color: #fff;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            font-weight: 500;
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .cart-button:hover {
            transform: translateY(-1px);
            box-shadow: 0 4px 12px rgba(255, 87, 34, 0.3);
        }
        .cart-count { 
            position: absolute;
            top: -8px;
            right: -8px;
            background: #4caf50;
            color: #fff;
            border-radius: 50%;
            padding: 3px 7px;
            font-size: 12px;
            box-shadow: 0 2px 6px rgba(255,68,68,0.4);
        }

        .categories { 
            display: grid; 
            grid-template-columns: repeat(auto-fit, minmax(240px, 1fr)); 
            gap: 20px; 
            margin-top: 24px;
            padding: 0 10px;
        }
        .category-card { 
            background: white; 
            border-radius: 16px; 
            padding: 24px; 
            text-align: center; 
            box-shadow: 0 4px 20px rgba(0,0,0,0.06); 
            cursor: pointer;
            transition: transform 0.3s, box-shadow 0.3s;
            position: relative;
            overflow: hidden;
        }
        .category-card:hover {
            transform: translateY(-2px);
            box-shadow: 0 8px 30px rgba(0,0,0,0.1);
        }
        .category-card h2 { 
            margin: 12px 0 0 0;
            color: #ff5722;
            font-weight: 600;
        }
        .category-card.active {
            background: #fff5f2;
            border: 2px solid #ff5722;
        }

        /* 商品列表 */
        #itemsContainer { 
            margin-top: 20px; 
            display: grid; 
            grid-template-columns: repeat(auto-fill, minmax(200px,1fr)); 
            gap: 16px;
            opacity: 0;
            transform: translateY(20px);
            transition: opacity 0.3s, transform 0.3s;
        }
        #itemsContainer.show {
            opacity: 1;
            transform: translateY(0);
        }
        .item-card { 
            background: white; 
            padding: 16px; 
            border-radius: 12px; 
            box-shadow: 0 4px 16px rgba(0,0,0,0.06);
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .item-card:hover {
            transform: translateY(-2px);
            box-shadow: 0 6px 24px rgba(0,0,0,0.1);
        }
        .item-card h3 { 
            margin: 0 0 8px 0; 
            font-size: 17px;
            color: #e65100;
        }
        .item-card p { 
            margin: 0 0 12px 0; 
            color: #ff5722;
            font-weight: 500;
        }
        .item-card button { 
            background: linear-gradient(45deg, #ff5722, #ff7043);
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 8px;
            cursor: pointer;
            font-weight: 500;
            transition: transform 0.2s, box-shadow 0.2s;
        }
        .item-card button:hover {
            transform: translateY(-1px);
            box-shadow: 0 4px 12px rgba(255, 87, 34, 0.3);
        }

        /* 購物車彈窗 */
        .modal { 
            display: none; 
            position: fixed; 
            inset: 0; 
            background: rgba(0,0,0,0.6); 
            align-items: center; 
            justify-content: center;
            backdrop-filter: blur(4px);
        }
        .modal.open { 
            display: flex;
            animation: modalFadeIn 0.3s ease-out;
        }
        @keyframes modalFadeIn {
            from { opacity: 0; transform: translateY(-20px); }
            to { opacity: 1; transform: translateY(0); }
        }
        .modal-content { 
            background: white; 
            width: 90%; 
            max-width: 520px; 
            border-radius: 16px; 
            padding: 24px;
            box-shadow: 0 20px 60px rgba(0,0,0,0.2);
        }
        .cart-item { 
            display: flex;
        #
](https://wd105087-star.github.io/restaurant-menu/)
